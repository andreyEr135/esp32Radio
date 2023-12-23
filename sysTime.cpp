#include "sysTime.h"

sysTime::sysTime(int _offset)
{
  ntpServer = "pool.ntp.org";
  gmtOffset_sec = 3600;
  daylightOffset_sec = 3600;
  offset = _offset;
}

void sysTime::syncTime()
{
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer.c_str());
}

String sysTime::getTime()
{
  String res;
  char str[10];
  memset(str,0, sizeof(str));
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)) {
    return "--:--";
  }
  sprintf(str, "%02d:%02d", timeinfo.tm_hour + offset, timeinfo.tm_min);
  res = (String)str;
  return res;
}