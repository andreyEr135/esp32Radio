#ifndef SYSTIME_H
#define SYSTIME_H

#include <iostream>
#include <string>

#include <Arduino.h>
#include "time.h"

class sysTime
{
  public:
    sysTime(int _offset = 0);
    void syncTime();
    String getTime();

    
  private:
    String ntpServer;
    long  gmtOffset_sec;
    int   daylightOffset_sec;

  
};



#endif 