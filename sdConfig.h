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

    String getListOfFiles();
    File getFile(String path);

    bool openFileForWrite(String name);
    bool writeToFile(uint8_t *buf, int size);
    bool closeFile();
    bool removeFile(String name);
    bool isFileOpened();

  private:
    bool initSD();
    String configFile;
    bool sdInited;
    String errorStr;
    SPIClass hspi;

    String weatherToken;
    float weatherLat;
    float weatherLon;

    File fl;
    bool fileOpened;
  
};




#endif 