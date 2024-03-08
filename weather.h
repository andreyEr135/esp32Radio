#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <string>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>



class weather
{
  public:
    weather(float _lat = 0, float _lon = 0, String _token = "");
    void getWeather();    
    bool isError();
    String getErrStr();

    String getCity();
    String getOblast();
    String getUptime();
    String getTemperature();
    String getCondition();
    String getPressure();
    String getHumidity();

    
  private:
    void getweatherFromServer();
    void getweatherFromLocal();
    bool saveWeatherToLocal(); 
    String weatherInfo;
    float lat, lon;
    String token;
    HTTPClient http;
    const char* host = "api.openweathermap.org";
    const char* url = "/data/2.5/weather?&units=metric&lang=ru";
    bool error;
    String errStr;

    String city;
    String obl;
    String uptime;
    String temperature;
    String condition;
    String pressure;
    String humidity;
    


  
};



#endif 