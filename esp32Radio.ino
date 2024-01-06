#define LGFX_USE_V1

#include <LovyanGFX.hpp>
#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
#include "globals.h"

#include "lvgl.h"

// Create an instance of the prepared class
#include <lvgl.h>

#include "sdConfig.h"
#include "uiMainPage.h"
#include "uiWeatherPage.h"

#include "listOfStations.h"

#include "uiModules.h"
#include "uiVolumeInfo.h"
#include "uiVolumePage.h"
#include "uiMenuPage.h"
#include "uiCurrentStationIcon.h"
#include "uiStationName.h"
#include "uiTitleLabel.h"
#include "uiWifiInfo.h"
#include "uiTimeInfo.h"
#include "uiPlayPauseBtn.h"
#include "uiPlayPauseIcon.h"
#include "uiVersionLabel.h"
#include "uiPrevBtn.h"
#include "uiNextBtn.h"
#include "uiMenuBtn.h"
#include "uiVolOffBtn.h"
#include "uiRadioStationInfo.h"

#include "uiCityName.h"
#include "uiOblName.h"
#include "uiConditionIcon.h"
#include "uiTempLabel.h"
#include "uiPressureLabel.h"
#include "uiHumInfo.h"





static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];


int tickWeather = 0;




void tickTimer(lv_timer_t * timer)
{
  if ((volDisplay) && (tickVolume > TIMEOUT_VOLUME_PAGE))
  {
    HideVolume();
    tickVolume = 0;
    return;
  }
  if ((listDisplay) && (tickStationList > TIMEOUT_STATIONLIST_PAGE))
  {
    HideMenuOfStations();
    reshowMenuBtn();
    tickStationList = 0;    
    return;
  }
  if (volDisplay) tickVolume++;
  if (listDisplay) tickStationList++;

  playPauseBtnChangeState(audio.isRunning());
  wifiInfoReDraw();
  reshowTimeStr();

  if (tickWeatherInfo == TIMEOUT_WEATHER_INFO) 
  {
    if (mainWin) showWeatherPage();
    tickWeatherInfo = 0;
  }

  if (tickWeather > TIMEOUT_WEATHER_GET+1) tickWeather = 0;
  if (tickWeather == 0)
  {
    weatherService->getWeather();
    writeTemp();
    if (!mainWin) reShowWeatherPage();
  }
  tickWeather++;
  tickWeatherInfo++;
}


void showBackground()
{
  LV_IMG_DECLARE(background);
  lv_obj_t *backgroundImg = lv_img_create(lv_scr_act());
  lv_img_set_src(backgroundImg, &background);
  lv_obj_set_pos(backgroundImg, 0, 0);  
}

// void createMenu()
// {
//   showVolumeBtnInfo();
//   showMenuBtn();
//   showVolumeOffBtn();
// }

// void showMainPage()
// {
//   mainWin = true;
//   showTimeStr();

//   showVersionStr();

//   showTempLabel();  

//   wifiInfoDraw();

//   showNameStationLabel();

//   showRadioStationInfo();

//   showCurrentRadioStationIcon();

//   showTitleInfoLabel();

//   showPlayPauseIcon();

//   showPrevBtn();

//   showPlayPauseBtn();

//   showNextBtn();

//   createMenu();

//   volDisplay = false;
//   listDisplay = false;

// }

// void showMainPageAfterWeather()
// {
//   mainWin = true;
//   hideNameCityLabel();
//   hideNameOblLabel();
//   conditionIconHide();
//   hidePressureLabel();
//   hideHumInfo();

//   reshowTimeInfo();
//   showVersionStr();
//   reShowTempLabel();

//   reShowNameStationLabel();
//   showRadioStationInfo();
//   showCurrentRadioStationIcon();
//   reShowTitleInfoLabel();

//   showPrevBtn();
//   showPlayPauseBtn();
//   showNextBtn();

// }

// void showWeatherPage()
// {
//   mainWin = false;
//   hideVersionStr();
//   hideRadioStationInfo();
//   hideCurrentRadioStationIcon();

//   hidePrevBtn();
//   hidePlayPauseBtn();
//   hideNextBtn();


//   reshowTimeInfo();
//   reShowNameStationLabel();
//   reShowTitleInfoLabel();

//   showNameCityLabel();

//   showNameOblLabel();

//   conditionIconDraw();

//   reShowTempLabel();

//   showPressureLabel();

//   showHumInfo();
// }

// void reShowWeatherPage()
// {
//   writeCityName();
//   writeOblName();
//   writePressure();
//   reShowHumInfo();
// }


// Create a slider and write its value on a label.
void CreateControls(void)
{
  /*Create a transition animation on width transformation and recolor.*/
  static lv_style_prop_t tr_prop[] = {LV_STYLE_TRANSFORM_WIDTH, LV_STYLE_IMG_RECOLOR_OPA};
  static lv_style_transition_dsc_t tr;
  lv_style_transition_dsc_init(&tr, tr_prop, lv_anim_path_linear, 0, 0, NULL);

  lv_style_init(&style_def);
  lv_style_set_text_color(&style_def, lv_color_white());
  lv_style_set_transition(&style_def, &tr);

  /*Darken the button when pressed and make it wider*/
  lv_style_init(&style_pr);
  lv_style_set_img_recolor_opa(&style_pr, LV_OPA_30);
  lv_style_set_img_recolor(&style_pr, lv_color_black());
  //lv_style_set_transform_width(&style_pr, 20);

  showBackground();

  showMainPage();
  

}


void displaySetup()
{
  tft.begin();
  tft.setRotation(3);
  tft.setBrightness(255);

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touch_read;
  lv_indev_drv_register(&indev_drv);  
}

void audioSetup()
{
  audio.setPinout(I2S_BCLK, I2S_LRCK, I2S_DOUT);
  audio.setVolume(volumeOut);    // Values from 0 to 21
}

bool wifiSetup()
{
  wifiConnect = false;
  audio_showstation("Waiting connection to WiFi");
  audio_showstreamtitle(ssid.c_str());
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  int t_sec = 0;
  while (WiFi.status() != WL_CONNECTED) 
  {
    t_sec++;
    if (t_sec > TIMEOUT_WIFI_CONNECT)
    {
      if (WiFi.status() != WL_CONNECTED)
      {
        audio_showstation("Connect to WiFi error");
        audio_showstreamtitle(ssid.c_str());
        return false;
      }
    }
    delay(1000);
  }  
  audio_showstation("Connected to WiFi");
  return true;
}

void setup() {
  audioPlaying = false;
  readConfig = new sdConfig();
  listStations = new listOfStations();
  sTime = new sysTime(TIME_OFFSET);
 
  displaySetup();
 
  volumeOut = 10;

  audioSetup();

  CreateControls();

  if (!readConfig->readConfig())
  {
    audio_showstation("Read config from SD card error");
    audio_showstreamtitle(readConfig->GetError().c_str());
    return;
  }

  weatherService = new weather(readConfig->getWeatherLat(), readConfig->getWeatherLon(), readConfig->getWeatherToken());
  
  if (wifiSetup())  
  {

    if (listStations->getCountOfStations() > 0)
    {
      currentStation = 0;
      audio.connecttohost(listStations->getUrlOfStation(listStations->getNameOfStations(currentStation)).c_str());
    }  else
    {
      audio_showstation("Radio Stations not found!");
    }
    sTime->syncTime();
    
    //if (!labelStationName) return;
    //lv_label_set_text_fmt(labelStationName, "%s", weatherService->getErrStr().c_str());    
  }

  tickWeatherInfo = 0;
  dispTimer = lv_timer_create(tickTimer, 1000,  NULL);

  delay(500); 

  playPauseBtnChangeState(audio.isRunning());
}


void loop() {
  audio.loop();
  lv_timer_handler();  
}

void audio_showstation(const char *info){
    writeStationName(info);
}

void audio_showstreamtitle(const char *info){
    writeTitle(info);
}
