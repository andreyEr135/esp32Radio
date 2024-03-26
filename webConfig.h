#ifndef WEBCONFIG_H
#define WEBCONFIG_H

#include <iostream>
#include <string>

#include <Arduino.h>

//#include <SPI.h>
//#include "SD.h"
//#include <ArduinoJson.h>

#include "globals.h"

#include <WiFiClient.h>
#include <ESP32WebServer.h>



//File root;

extern ESP32WebServer *server;
bool serverStart();
//bool opened = false;






#endif 