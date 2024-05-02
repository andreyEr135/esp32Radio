#ifndef OTASERVER_H
#define OTASERVER_H

#include <iostream>
#include <string>

#include <Arduino.h>

//#include <SPI.h>
//#include "SD.h"
//#include <ArduinoJson.h>

#include "globals.h"

#include <WiFiClient.h>
//#include <ESP32WebServer.h>

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>



//File root;

//extern ArduinoOTA *otaServer;
//ESP32WebServer *server;
void serverOtaHandle();
bool serverOtaStart();
//bool opened = false;






#endif 