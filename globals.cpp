#include "globals.h"

#include "uiMainPage.h"
#include "uiVolumePage.h"

// SD Config
sdConfig *readConfig;

// Flag of main window
bool mainWin;
int tickWeatherInfo;

// StationInfo structure and variables
bool listDisplay;
listOfStations *listStations;
int currentStation = 0;
// extern int countOfStations = 0;
// _stationInfo stationInfo;
// struct _stationInfo stationsInfo[MAX_STATIONS];

RadioMetadata *rdMetadata;

// Create Audio objects
bool audioPlaying;
Audio audio;

// WiFi settings
bool wifiConnect;
String ssid;
String password;

// SysTime
sysTime *sTime;

// Weather
weather *weatherService;

// Battery status
batteryStatus *battery;

// WebServer
//ESP32WebServer *server;

// LGFX
LGFX tft;

// Volume Info
int tickVolume;
bool volDisplay;
int prevVol;
int volumeOut;

// Display
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  tft.endWrite();
  lv_disp_flush_ready(disp);
}

// Sensor
void my_touch_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;
  bool touched = tft.getTouch(&touchX, &touchY);
  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = touchX;
    data->point.y = touchY;
    if ( (!volDisplay) && (!listDisplay) )
    {
      if (data->point.y < 269)
        if (!mainWin) showMainPageAfterWeather();
    } else
    {
      if (volDisplay)
      {
        if (data->point.y > 269) {
          tickWeatherInfo = 0;
          return;
        }
        if ( ( (data->point.x > 100) && (data->point.x < 100 + 300) ) && ( (data->point.y > 100) && (data->point.y < 100+90) ) ) 
        {
          tickWeatherInfo = 0;
          return;
        } 
        HideVolume();
        tickVolume = 0;
      }
    }
    tickWeatherInfo = 0;
  }
}

int getPosOfCurrentRadio()
{
  const int minPos = 15;
  const int maxPos = 7 + 426 - 8;
  int step = (maxPos - minPos) / (listStations->getCountOfStations() - 1);
  if (currentStation == 0) return 15;
  return (currentStation*step);
}