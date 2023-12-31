#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <string>

#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>



class weather
{
  public:
    weather(float _lat = 0, float _lon = 0, String _token = "");
    void getweatherFromServer();
    void getweatherFromLocal();
    bool isError();
    String getErrStr();

    
  private:
    bool saveWeatherToLocal(); 
    String weatherInfo;
    float lat, lon;
    String token;
    HTTPClient http;
    const char* serverName = "https://api.weather.yandex.ru/v2/forecast?";
    bool error;
    String errStr;

    int updateTime;
    int temp;
    


  
};



#endif 