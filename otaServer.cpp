#include "otaServer.h"

#include "uiApName.h"
#include "uiApPswd.h"
#include "uiApIp.h"

//ArduinoOTA *otaServer;


void serverOtaHandle()
{
  ArduinoOTA.handle();
}

bool serverOtaStart()
{
  WiFi.softAP("WiFiRadio", "12345678"); //Network and password for the access point genereted by ESP32

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  


  writeApName("WiFiRadio");
  writeApPswd("12345678");
  writeApIp(WiFi.softAPIP().toString().c_str());
  otaServerMode = true;
  return true;
}


