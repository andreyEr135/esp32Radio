#ifndef SDCONFIG_H
#define SDCONFIG_H

#include <iostream>
#include <string>

#include <Arduino.h>

#include <SPI.h>
#include "SD.h"
#include <ArduinoJson.h>

#include "globals.h"

class sdConfig
{
  public:
    sdConfig();
    bool readConfig();
    String GetError();

    String getWeatherToken();
    float getWeatherLat();
    float getWeatherLon();

    bool writeWeatherInfo(String info);
    String readWeatherInfo();

    bool writeCurrentStation(int id);
    int readOldStation();

    bool writeCurrentVolume(int vol);
    int  readOldVolume();

  private:
    bool initSD();
    String configFile;
    bool sdInited;
    String errorStr;
    SPIClass hspi;

    String weatherToken;
    float weatherLat;
    float weatherLon;
  
};




#endif 