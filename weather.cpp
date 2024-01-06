#include "weather.h"

#include "globals.h"

using namespace std;

weather::weather(float _lat, float _lon, String _token)
{
  weatherInfo = "";
  lat = _lat;
  lon = _lon;
  token = _token;
  if ((lat > 0) && (lon > 0) && (token != "")) error = false;
  else error = true;
}

void weather::getWeather()
{
  getweatherFromLocal();
  if (uptime != 0)
  {
    unsigned long tsync;
    sscanf(uptime.c_str(), "%lu", &tsync);

    if (sTime->getTimeLong() - tsync > 30*60 )
      getweatherFromServer();
  } else getweatherFromServer();
}

void weather::getweatherFromServer()
{
  String str_copy;
  String str;
  bool founded = false;

  char buff[2500];

	String _url = (String)url + "&lat=" + String(lat, 6) + "&lon=" + String(lon, 6) + "&limit=1";
  WiFiClient client;
  client.stop();
  http.begin(client, host, 80, _url, true);
	http.addHeader("X-Yandex-API-Key", token);
  int httpCode = http.GET();
  
  if (httpCode != 200)
  {
    error = true;
    errStr = "No weather data";
    return;
  }
  ssize_t sz = http.getStream().available();
  if (sz < sizeof(buff))
  {
    error = true;
    errStr = "Get data weather error";
    return;
  } 
  
  int c = http.getStream().readBytes(buff, ((sz > sizeof(buff)) ? sizeof(buff) : sz));
    
  str = (String)buff;

  if (str.indexOf("geo_object") > 0)
  {
    founded = false;
    str_copy = str;
    str_copy = str_copy.substring(str_copy.indexOf("geo_object"));
    
    if (str_copy.indexOf("province") > 0)
    {
        if (str_copy.indexOf("name") > 0)
        {
            str_copy = str_copy.substring(str_copy.indexOf("name")+7);    
            if (str_copy.indexOf('\"') > 0)
            { 
                str_copy = str_copy.substring(0,str_copy.indexOf('\"'));    
                city = str_copy;   
                str_copy = "";
                founded = true;
            }
        } 
    } 
  } 
  if (str.indexOf("province") > 0)
  {
    founded = false;
    str_copy = str;
    str_copy = str_copy.substring(str_copy.indexOf("province"));
    if (str_copy.indexOf("name") > 0)
    {
        str_copy = str_copy.substring(str_copy.indexOf("name")+7);
        if (str_copy.indexOf('\"') > 0)
        {
            str_copy = str_copy.substring(0,str_copy.indexOf('\"'));
            obl = str_copy;
            str_copy = "";
            founded = true;
        } 
    } 
  }
  if (str.indexOf("fact") > 0)
  {
    founded = false;
    str_copy = str;
    str_copy = str_copy.substring(str_copy.indexOf("fact"));
    
    if (str_copy.indexOf("uptime") > 0)
    {
        str_copy = str_copy.substring(str_copy.indexOf("uptime")+8);
        if (str_copy.indexOf(',') > 0)
        {
            str_copy = str_copy.substring(0,str_copy.indexOf(','));
            uptime = str_copy;
            str_copy = "";
            founded = true;
        } 
    } 
  }
  if (str.indexOf("fact") > 0)
  {
    founded = false;
    str_copy = str;
    str_copy = str_copy.substring(str_copy.indexOf("fact"));
    if (str_copy.indexOf("temp") > 0)
    {
        str_copy = str_copy.substring(str_copy.indexOf("temp")+6);
        if (str_copy.indexOf(',') > 0)
        {
            str_copy = str_copy.substring(0,str_copy.indexOf(','));
            temperature = str_copy;
            str_copy = "";
            founded = true;
        } 
    } 
  }
  if (str.indexOf("fact") > 0)
  {
    founded = false;
    str_copy = str;
    str_copy = str_copy.substring(str_copy.indexOf("fact"));

    if (str_copy.indexOf("condition") > 0)
    { 
        str_copy = str_copy.substring(str_copy.indexOf("condition")+12);
        if (str_copy.indexOf('\"') > 0)
        {
            str_copy = str_copy.substring(0,str_copy.indexOf('\"'));
            condition = str_copy;
            str_copy = "";
            founded = true;
        } 
    } 
  }
  
  if (str.indexOf("fact") > 0)
  {
    founded = false;
    str_copy = str;
    str_copy = str_copy.substring(str_copy.indexOf("fact"));

    if (str_copy.indexOf("pressure_mm") > 0)
    {
        str_copy = str_copy.substring(str_copy.indexOf("pressure_mm")+13);
        if (str_copy.indexOf(',') > 0)
        {
            str_copy = str_copy.substring(0,str_copy.indexOf(','));
            pressure = str_copy;
            str_copy = "";
            founded = true;
        } 
    } 
  }
  if (str.indexOf("fact") > 0)
  {
    founded = false;
    str_copy = str;
    str_copy = str_copy.substring(str_copy.indexOf("fact"));

    if (str_copy.indexOf("humidity") > 0)
    { 
        str_copy = str_copy.substring(str_copy.indexOf("humidity")+10);
        if (str_copy.indexOf(',') > 0)
        {
            str_copy = str_copy.substring(0,str_copy.indexOf(','));
            humidity = str_copy;
            str_copy = "";
            founded = true;
        } 
    } 
  }

  http.end();
  saveWeatherToLocal();
}

void weather::getweatherFromLocal()
{
  String strRead = readConfig->readWeatherInfo();
  
  String str = strRead;
  while (str != "")
  {
    if (str.indexOf(';') > 0)
    {
      String param = str.substring(0, str.indexOf(';'));
      str = str.substring(str.indexOf(';')+1);
      if (param.indexOf("uptime=") >=0)
      {
        uptime = param.substring(7);
      } else if (param.indexOf("city=") >=0)
      {
        city = param.substring(5);
      } else if (param.indexOf("obl=") >=0)
      {
        obl = param.substring(4);
      } else if (param.indexOf("temp=") >=0)
      {
        temperature = param.substring(5);
      } else if (param.indexOf("cond=") >=0)
      {
        condition = param.substring(5);
      } else if (param.indexOf("pressure=") >=0)
      {
        pressure = param.substring(9);
      } else if (param.indexOf("hum=") >=0)
      {
        humidity = param.substring(4);
      }
    } else break;
  }
}

    
bool weather::saveWeatherToLocal()
{
  String strRec = "uptime=" + uptime + ";city=" + city + ";obl=" + obl + ";temp=" + temperature + ";cond=" + condition + ";pressure=" + pressure + ";hum=" + humidity + ";";
  bool res = readConfig->writeWeatherInfo(strRec);
  return res;
}

bool weather::isError()
{
  return error;
}

String weather::getErrStr()
{
  return errStr;
}

String weather::getCity()
{
  return city;
}
String weather::getOblast()
{
  return obl;
}
String weather::getUptime()
{
  return uptime;
}
String weather::getTemperature()
{
  return temperature;
}
String weather::getCondition()
{
  return condition;
}
String weather::getPressure()
{
  return pressure;
}
String weather::getHumidity()
{
  return humidity;
}

