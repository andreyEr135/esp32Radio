#ifndef RADIOMETADATA_H
#define RADIOMETADATA_H

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



class RadioMetadata
{
  public:
    RadioMetadata();
    String getMetadata(String station);    
    bool isError();
    String getErrStr();
    
  private:
    String token;
    HTTPClient http;
    const char* host = "pic.fmplay.ru";
    const char* url = "/stations/";
    bool error;
    String errStr;  
};



#endif 