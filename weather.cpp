#include "weather.h"

#define ARDUINOJSON_SLOT_OFFSET_SIZE 100000

weather::weather(float _lat, float _lon, String _token)
{
  weatherInfo = "";
  lat = _lat;
  lon = _lon;
  token = _token;
  if ((lat > 0) && (lon > 0) && (token != "")) error = false;
  else error = true;
}

void weather::getweatherFromServer()
{
	//String recv_token = "X-Yandex-API-Key:" + token;	
	//WiFiClient client;		
	// Sending POST request for Location Data.
  char request[255];
  memset(request, 0, sizeof(request));
  sprintf(request, "%slat=%f&lon=%f&limit=1", serverName, lat, lon);
  http.begin(request);
  http.addHeader("X-Yandex-API-Key", token); // Adding Bearer token as HTTP header
  
  if (http.GET() > 0) {
    char buff[512];
    ssize_t sz = http.getStream().available();
    ssize_t len = sz;
    while (len > 0 || len == -1)
    {
      String str = "";
      int beg = 0;
      int end = 0;
      // read up to 128 byte
      int c = http.getStream().readBytes(buff, ((sz > sizeof(buff)) ? sizeof(buff) : sz));
      if ((strstr(buff, "uptime") != 0) && (strstr(buff, "temp") != 0))
      {
        str = (String)buff;
        beg = str.indexOf("uptime");
        end = str.indexOf("temp");

        str = str.substring(beg, end);
        str = str.substring(8);
        str.setCharAt(str.length() - 2, 0);
        updateTime = str.toInt();
        errStr = str; 
      }

      if ((strstr(buff, "temp") != 0) && (strstr(buff, "feels_like") != 0))
      {
        errStr = "temp and feels_like founded!"; 
        str = (String)buff;
        beg = str.indexOf("temp");
        end = str.indexOf("feels_like");

        str = str.substring(beg);
        str = str.substring(6);
        str.setCharAt(10, 0);
        //updateTime = str.toInt();
        errStr = str; 
      }


    
      if (len > 0) {
        len -= c;
      }
    }
    //http.getStream().readBytes(buff, 32);
    //errStr = (String)buff;    
          // выводим ответ сервера
      //StaticJsonDocument<16384> readData;
      //StaticJsonDocument<64> filter;
      //filter["fact"][0]["temp"] = true;
      //filter["fact"][1]["feels_like"] = true;
      //DynamicJsonDocument readData(2000);
      //String res = "{\"now\": 1703707370,\"now_dt\": \"2023-12-27T20:02:50.600975Z\",\"info\": {\"n\": true,\"geoid\": 10747,\"url\": \"https://yandex.ru/pogoda/10747?lat=55.4242&lon=37.5547\",\"lat\": 55.4242,\"lon\": 37.5547,\"tzinfo\": {\"name\": \"Europe/Moscow\",\"abbr\": \"MSK\",\"dst\": false,\"offset\": 10800},\"def_pressure_mm\": 746,\"def_pressure_pa\": 994,\"slug\": \"10747\",\"zoom\": 10,\"nr\": true,\"ns\": true,\"nsr\": true,\"p\": false,\"f\": true,\"_h\": false}}";
      //http.getStream().find("\"info\":{");
      //do {
      //  DeserializationError error = deserializeJson(readData, http.getStream(), DeserializationOption::Filter(filter));    
      //  if (error) 
      //  {
      //    errStr = (String)error.f_str();
      //  } else {
      //    int temp = readData["feels_like"];
      //    char s[15]; sprintf(s, "%d", temp);
      //    errStr = (String)s + "C";
          //JsonObject tzinfo = readData["tzinfo"];
          //const char* tzinfo_name = tzinfo["name"];
          //errStr = tzinfo_name;
      //  }
      //} while (http.getStream().findUntil(",","}\"geo_object\""));
      
      
  } else
  {
    errStr = token;
  }  
  // Send HTTP POST request
  /*httpResponseCode = http.POST(httpRequestData);
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  
  if (httpResponseCode>0) {
      payload = http.getString();
      Serial.println(payload);
  }*/
// Free resources
  http.end();

}
void weather::getweatherFromLocal()
{

}

    
bool weather::saveWeatherToLocal()
{

  return true;
}

bool weather::isError()
{
  return error;
}

String weather::getErrStr()
{
  return errStr;
}

