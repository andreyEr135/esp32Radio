#include "weather.h"

#include "globals.h"

using namespace std;
String httpGETRequest(const char* serverName);

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

	String _url = (String)url + "&lat=" + String(lat, 4) + "&lon=" + String(lon, 4) + "&appid=" + token;

  WiFiClient client;
  client.stop();

  http.begin(client, host, 80, _url, true);
  int httpCode = http.GET();
  
  if (httpCode != 200)
  {
    error = true;
    errStr = "No weather data";
    return;
  }  
    
  ssize_t sz = http.getStream().available();  
  int c = http.getStream().readBytes(buff, ((sz > sizeof(buff)) ? sizeof(buff) : sz));
  str = (String)buff;

  if (str == "")
  {
    error = true;
    errStr = "No data";
    return;
  }
 
  if (str.indexOf("weather") > 0)
  {
      founded = false;
      str_copy = str;
      str_copy = str_copy.substring(str_copy.indexOf("weather"));
      
      if (str_copy.indexOf("main") > 0)
      {
          str_copy = str_copy.substring(str_copy.indexOf("main")+7);
          if (str_copy.indexOf('\"') > 0)
          {
              str_copy = str_copy.substring(0,str_copy.indexOf('\"'));
              if (str_copy == "Clear") condition = "clear";
              else if (str_copy == "Clouds") condition = "cloudy";
              else if (str_copy == "Rain") condition = "rain";
              else if (str_copy == "Snow") condition = "snow";
              else if (str_copy == "Thunderstorm") condition = "thunderstorm";              
              str_copy = "";
              founded = true;
          }
      } 
  }

  if (str.indexOf("weather") > 0)
  {
      founded = false;
      str_copy = str;
      str_copy = str_copy.substring(str_copy.indexOf("weather"));
      
      if (str_copy.indexOf("description") > 0)
      {
          str_copy = str_copy.substring(str_copy.indexOf("description")+14);
          if ((int)str_copy.indexOf('\"') > 0)
          {
              str_copy = str_copy.substring(0,str_copy.indexOf('\"'));
              if (str_copy == "ясно") condition = "clear";
              else if (str_copy == "рассеянные облака") condition = "partly-cloudy";
              else if (str_copy == "пасмурная облачность") condition = "overcast";
              else if (str_copy == "легкий дождь, дождь") condition = "rain";
              else if (str_copy == "ливень дождь") condition = "heavy-rain";
              else if (str_copy == "легкий дождь") condition = "light-rain";
              else if (str_copy == "сильный ливень") condition = "showers";
              else if (str_copy == "мокрый снег") condition = "wet-snow";

              else if (str_copy == "легкий снег") condition = "light-snow";
              else if (str_copy == "снег") condition = "snow";
              else if (str_copy == "сильный снегопад") condition = "snow-showers";

              else if (str_copy == "ледяной дождь") condition = "hail";
              else if (str_copy == "гроза") condition = "thunderstorm";
              else if (str_copy == "гроза с дождем") condition = "thunderstorm-with-rain";
              else if (str_copy == "гроза с сильным дождем") condition = "thunderstorm-with-hail";
              str_copy = "";
              founded = true;
          }
      } 
  } 
  
  if (str.indexOf("temp") > 0)
  {
      founded = false;
      str_copy = str;
      str_copy = str_copy.substring(str_copy.indexOf("temp")+6);
      
      if (str_copy.indexOf('\"') > 0)
      {
          str_copy = str_copy.substring(0,str_copy.indexOf(','));
          float temp;
          sscanf(str_copy.c_str(), "%f", &temp);
          int t = (int)temp;
          temperature = (String)t;          
          str_copy = "";
          founded = true;
      }
  }

  if (str.indexOf("pressure") > 0)
  {
      founded = false;
      str_copy = str;
      str_copy = str_copy.substring(str_copy.indexOf("pressure")+10);
      
      if ((int)str_copy.indexOf('\"') > 0)
      {
          str_copy = str_copy.substring(0,str_copy.indexOf(','));
          int press = atoi(str_copy.c_str());
          press = press*0.75;
          pressure = (String)press;
          str_copy = "";
          founded = true;
      }
  }

  if (str.indexOf("humidity") > 0)
  {
      founded = false;
      str_copy = str;
      str_copy = str_copy.substring(str_copy.indexOf("humidity")+10);
      
      if (str_copy.indexOf('}') > 0)
      {
          str_copy = str_copy.substring(0,str_copy.indexOf('}'));
          humidity = str_copy;
          str_copy = "";
          founded = true;
      }
  }

  if (str.indexOf("dt") > 0)
  {
      founded = false;
      str_copy = str;
      str_copy = str_copy.substring(str_copy.indexOf("dt")+4);
      
      if (str_copy.indexOf(',') > 0)
      {
          str_copy = str_copy.substring(0,str_copy.indexOf(','));
          uptime = str_copy;
          
          str_copy = "";
          founded = true;
      }
  }

  if (str.indexOf("name") > 0)
  {
      founded = false;
      str_copy = str;
      str_copy = str_copy.substring(str_copy.indexOf("name")+7);
      
      if (str_copy.indexOf('\"') > 0)
      {
          str_copy = str_copy.substring(0,str_copy.indexOf('\"'));
          city = str_copy;
          
          str_copy = "";
          founded = true;
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

