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
  
  private:
    bool initSD();
    String configFile;
    bool sdInited;
    String errorStr;
    SPIClass hspi;
  public:
    sdConfig();
    bool readConfig();
    String GetError();
};



#endif 