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
#include "listOfStations.h"


static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

sdConfig *readConfig;


static lv_obj_t *labelStationName;
static lv_obj_t *labelTitle;

TaskHandle_t volumeDispTask;
lv_timer_t *volTimer;
bool volDisplay = false;
int timeOutVolume;
static lv_obj_t *pageVolume;
static lv_style_t stVolLabelStyle;
static lv_obj_t *labelMainVolume;
lv_obj_t *iconPlayPause;


bool listDisplay = false;
int timeOutStationList;
static lv_obj_t *pageStationsList;
static lv_obj_t *labelListTitle;
static lv_obj_t *menuOfStations;

static lv_obj_t *volOffBtn; 



static lv_obj_t *label;
static lv_obj_t *slider;


void HideMenuOfStations()
{
  lv_obj_del(labelListTitle);
  lv_obj_del(menuOfStations);
  lv_obj_del(pageStationsList);
  labelListTitle = NULL;
  menuOfStations = NULL;
  pageStationsList = NULL;
  listDisplay = false;
}

void HideVolume()
{
  lv_obj_del(slider);
  lv_obj_del(label);
  lv_obj_del(pageVolume);
  slider = NULL;
  label = NULL;
  pageVolume = NULL;
  volDisplay = false;
}


void tickTimer(lv_timer_t * timer)
{
  if ((volDisplay) && (timeOutVolume > 10))
  {
    HideVolume();
    timeOutVolume = 0;
    lv_timer_pause(volTimer);
    return;
  }
  if ((listDisplay) && (timeOutStationList > 10))
  {
    HideMenuOfStations();
    timeOutStationList = 0;    
    return;
  }
  if (volDisplay) timeOutVolume++;
  if (listDisplay) timeOutStationList++;
}




static void eventListClickedHandler(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * btn = lv_event_get_target(e);
  if(code == LV_EVENT_CLICKED) {
    currentStation = listStations->getIdOfStation((String)lv_list_get_btn_text(menuOfStations, btn));
    write_stationName(listStations->getNameOfStations(currentStation).c_str());
    audio.connecttohost(listStations->getUrlOfStation((String)lv_list_get_btn_text(menuOfStations, btn)).c_str());
    //audio.connecttohost(stationsInfo[currentStation].url.c_str());    
    HideMenuOfStations();
  }
}

void CreateMenuOfStations()
{
  /* Create page of list stations */
  pageStationsList = lv_obj_create(lv_scr_act()); /*Create a parent object on the current screen*/
  lv_obj_set_size(pageStationsList, 390, 300);
  lv_obj_set_pos(pageStationsList, 10, 10);

  static lv_style_t stLabelStyle;
  lv_style_init(&stLabelStyle);
  lv_style_set_text_font(&stLabelStyle, &lv_font_montserrat_18);
  labelListTitle = lv_label_create(pageStationsList);
  lv_label_set_text_fmt(labelListTitle, "Stations list");
  lv_obj_set_pos(labelListTitle, 120, 0);
  lv_obj_add_style(labelListTitle, &stLabelStyle, LV_PART_MAIN);

  menuOfStations = lv_list_create(pageStationsList);
  lv_obj_set_size(menuOfStations, 355, 220);
  lv_obj_set_pos(menuOfStations, 0, 35);
  
  lv_obj_t *list_btn;

  for (int i = 0; i < listStations->getCountOfStations(); i++)
  {
    list_btn = lv_list_add_btn(menuOfStations, NULL, listStations->getNameOfStations(i).c_str());
    //list_btn = lv_list_add_btn(menuOfStations, NULL, stationsInfo[i].name.c_str());
    lv_obj_add_event_cb(list_btn, eventListClickedHandler, LV_EVENT_CLICKED, NULL);
  }
  listDisplay = true;
}



static void slider_event_cb(lv_event_t *e)
{
  LV_IMG_DECLARE(vol_off);
  LV_IMG_DECLARE(vol_offed);
  timeOutVolume = 0;
  // Refresh the text
  lv_label_set_text_fmt(label, "Volume %" LV_PRId32, lv_slider_get_value(slider));
  volumeOut = lv_slider_get_value(slider);
  lv_label_set_text_fmt(labelMainVolume, "Vol  %d", volumeOut);
  audio.setVolume(volumeOut);

  if (volumeOut == 0)
  {
    lv_color_t colour;
    colour.ch.red   = 0xFF;
    colour.ch.green = 0x00;
    colour.ch.blue  = 0x00;
    lv_style_set_text_color(&stVolLabelStyle, colour);
    lv_obj_add_style(labelMainVolume, &stVolLabelStyle, LV_PART_MAIN);
    lv_imgbtn_set_src(volOffBtn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_offed, NULL);
    
  } else
  {
    if (prevVol == 0) 
    {
      lv_color_t colour;
      colour.ch.red   = 0x00;
      colour.ch.green = 0x00;
      colour.ch.blue  = 0x00;
      lv_style_set_text_color(&stVolLabelStyle, colour);
      lv_obj_add_style(labelMainVolume, &stVolLabelStyle, LV_PART_MAIN);
      lv_imgbtn_set_src(volOffBtn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_off, NULL);
    }
  }
  prevVol = volumeOut;
}

static void eventPrevStationBtn(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
      currentStation--;
      if (currentStation < 0) currentStation = listStations->getCountOfStations() - 1;
      write_stationName(listStations->getNameOfStations(currentStation).c_str());
      audio.connecttohost(listStations->getUrlOfStation(listStations->getNameOfStations(currentStation)).c_str());
      //audio.connecttohost(stationsInfo[currentStation].url.c_str()); 
    }
}

static void eventNextStationBtn(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
      currentStation++;
      if (currentStation > listStations->getCountOfStations() - 1) currentStation = 0;
      audio.connecttohost(listStations->getUrlOfStation(listStations->getNameOfStations(currentStation)).c_str());
      //audio.connecttohost(stationsInfo[currentStation].url.c_str()); 
      write_stationName(listStations->getNameOfStations(currentStation).c_str());
    }
}


static void eventPlayPauseBtn(lv_event_t * e)
{
    LV_IMG_DECLARE(playBtn);
    LV_IMG_DECLARE(pauseBtn);
    LV_IMG_DECLARE(playIcon);
    LV_IMG_DECLARE(pauseIcon);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
      audio.pauseResume();
      if (audio.isRunning())
      {
        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED, NULL, &pauseBtn, NULL);
        lv_img_set_src(iconPlayPause, &playIcon);
        lv_obj_set_pos(iconPlayPause, 14, 120);
      }
      else
      {
        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED, NULL, &playBtn, NULL);
        lv_img_set_src(iconPlayPause, &pauseIcon);
        lv_obj_set_pos(iconPlayPause, 26, 115);
      }

    }
}

static void eventMenuBtn(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
      if (!listDisplay) {
        if (volDisplay) HideVolume();
        CreateMenuOfStations();
        lv_timer_reset(volTimer);
        lv_timer_resume(volTimer);        
      }
      else 
      {
        HideMenuOfStations();
        lv_timer_pause(volTimer);
      }
    }
}



static void eventVolBtn(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        if (volDisplay) {
          vTaskSuspend(volumeDispTask);
          lv_obj_del(slider);
          lv_obj_del(label);
          lv_obj_del(pageVolume);
          slider = NULL;
          label = NULL;
          pageVolume = NULL;
          volDisplay = false;
          timeOutVolume = 0;
          lv_timer_pause(volTimer);
        } else
        {
          if (listDisplay) HideMenuOfStations();
          /* Create page of volume */
          pageVolume = lv_obj_create(lv_scr_act()); /*Create a parent object on the current screen*/
          lv_obj_set_size(pageVolume, 300, 90);
          lv_obj_align(pageVolume, LV_ALIGN_CENTER, 0, 0);

          slider = lv_slider_create(pageVolume);
          lv_obj_set_width(slider, 210);                                              // Set the width
          lv_obj_center(slider);                                                      // Align to the center of the parent (screen)
          lv_slider_set_range(slider, 0, 21);
          lv_slider_set_value(slider, volumeOut, LV_ANIM_ON);
          lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL); // Assign an event function

          // Create a label above the slider
          static lv_style_t stVolPageLabelStyle;
          lv_style_init(&stVolPageLabelStyle);
          lv_style_set_text_font(&stVolPageLabelStyle, &lv_font_montserrat_18);

          label = lv_label_create(pageVolume);
          lv_obj_add_style(label, &stVolPageLabelStyle, LV_PART_MAIN);
          lv_label_set_text_fmt(label, "Volume %" LV_PRId32, lv_slider_get_value(slider));
          lv_obj_align_to(label, slider, LV_ALIGN_OUT_TOP_MID, 0, -15); // Align top of the slider
          volDisplay = true;
          timeOutVolume = 0;
          lv_timer_reset(volTimer);
          lv_timer_resume(volTimer);         
        }
    }
}

static void eventVolOffBtn(lv_event_t * e)
{
    static int oldVolume;
    LV_IMG_DECLARE(vol_off);
    LV_IMG_DECLARE(vol_offed);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
      lv_color_t colour;
      if (volumeOut == 0)
      {
        volumeOut = oldVolume;
        if (slider) lv_slider_set_value(slider, volumeOut, LV_ANIM_ON);
        if (label) lv_label_set_text_fmt(label, "Volume %" LV_PRId32, lv_slider_get_value(slider));
        lv_label_set_text_fmt(labelMainVolume, "Vol  %d", volumeOut);
        colour.ch.red   = 0x00;
        colour.ch.green = 0x00;
        colour.ch.blue  = 0x00;
        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_off, NULL);
      } else
      {
        oldVolume = volumeOut;
        volumeOut = 0;
        if (slider) lv_slider_set_value(slider, volumeOut, LV_ANIM_ON);
        if (label) lv_label_set_text_fmt(label, "Volume %" LV_PRId32, lv_slider_get_value(slider));
        lv_label_set_text_fmt(labelMainVolume, "Vol  %d", volumeOut);
        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_offed, NULL);
        colour.ch.red   = 0xFF;
        colour.ch.green = 0x00;
        colour.ch.blue  = 0x00;
      }
      lv_style_set_text_color(&stVolLabelStyle, colour);
      lv_obj_add_style(labelMainVolume, &stVolLabelStyle, LV_PART_MAIN);
      audio.setVolume(volumeOut);
      prevVol = volumeOut;
    }
}







// Create a slider and write its value on a label.
void CreateControls(void)
{
  LV_IMG_DECLARE(menu);
  LV_IMG_DECLARE(volume);
  LV_IMG_DECLARE(vol_off);
  LV_IMG_DECLARE(vol_offed);

  LV_IMG_DECLARE(playIcon);
  LV_IMG_DECLARE(pauseIcon);

  LV_IMG_DECLARE(prevStationBtn);
  LV_IMG_DECLARE(playBtn);
  LV_IMG_DECLARE(pauseBtn);
  LV_IMG_DECLARE(nextStationBtn);
 

  volTimer = lv_timer_create(tickTimer, 1000,  NULL);
  lv_timer_pause(volTimer);

  /*Create a transition animation on width transformation and recolor.*/
  static lv_style_prop_t tr_prop[] = {LV_STYLE_TRANSFORM_WIDTH, LV_STYLE_IMG_RECOLOR_OPA};
  static lv_style_transition_dsc_t tr;
  lv_style_transition_dsc_init(&tr, tr_prop, lv_anim_path_linear, 0, 0, NULL);

  static lv_style_t style_def;
  lv_style_init(&style_def);
  lv_style_set_text_color(&style_def, lv_color_white());
  lv_style_set_transition(&style_def, &tr);

  /*Darken the button when pressed and make it wider*/
  static lv_style_t style_pr;
  lv_style_init(&style_pr);
  lv_style_set_img_recolor_opa(&style_pr, LV_OPA_30);
  lv_style_set_img_recolor(&style_pr, lv_color_black());
  //lv_style_set_transform_width(&style_pr, 20);


  /*  Create menus buttons  */
  /*Create an menu button*/
  lv_obj_t * menuBtn = lv_imgbtn_create(lv_scr_act());
  lv_imgbtn_set_src(menuBtn, LV_IMGBTN_STATE_RELEASED, NULL, &menu, NULL);
  lv_obj_add_style(menuBtn, &style_def, 0);
  lv_obj_add_style(menuBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(menuBtn, 50, 50);
  lv_obj_add_event_cb(menuBtn, eventMenuBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(menuBtn, screenWidth - 60, 16);

  /*Create an volume button*/
  lv_obj_t * volBtn = lv_imgbtn_create(lv_scr_act());
  lv_imgbtn_set_src(volBtn, LV_IMGBTN_STATE_RELEASED, NULL, &volume, NULL);
  lv_obj_add_style(volBtn, &style_def, 0);
  lv_obj_add_style(volBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(volBtn, 50, 50);
  lv_obj_add_event_cb(volBtn, eventVolBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(volBtn, screenWidth - 60, 16 + 50 + 63);

  /*Create an volume_off button*/
  volOffBtn = lv_imgbtn_create(lv_scr_act());
  if (volumeOut == 0) lv_imgbtn_set_src(volOffBtn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_offed, NULL);
  else lv_imgbtn_set_src(volOffBtn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_off, NULL);
  lv_obj_add_style(volOffBtn, &style_def, 0);
  lv_obj_add_style(volOffBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(volOffBtn, 50, 50);
  lv_obj_add_event_cb(volOffBtn, eventVolOffBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(volOffBtn, screenWidth - 60, 16 + 2*50 + 2*63);

  /*  Create main widget buttons and infos  */
  static lv_obj_t *labelVersion = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelVersion, "Network Radio v1.0");
  lv_obj_set_pos(labelVersion, 5, 5);


  
  lv_style_init(&stVolLabelStyle);
  lv_style_set_text_font(&stVolLabelStyle, &lv_font_montserrat_16);
  lv_color_t colour;
  if (volumeOut == 0) 
  {
    colour.ch.red   = 0xFF;
    colour.ch.green = 0x00;
    colour.ch.blue  = 0x00;
  } else
  {
    colour.ch.red   = 0x00;
    colour.ch.green = 0x00;
    colour.ch.blue  = 0x00;
  }
  lv_style_set_text_color(&stVolLabelStyle, colour);

  labelMainVolume = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelMainVolume, "Vol  %d", volumeOut);
  
  lv_obj_set_pos(labelMainVolume, 335, 10);
  lv_obj_add_style(labelMainVolume, &stVolLabelStyle, LV_PART_MAIN);


  /* Create an play or pause icon */
  iconPlayPause = lv_img_create(lv_scr_act());
  if (audio.isRunning() == true) 
  {
    lv_img_set_src(iconPlayPause, &playIcon);
    lv_obj_set_pos(iconPlayPause, 14, 120);
  }
  else
  {
    lv_img_set_src(iconPlayPause, &pauseIcon);
    lv_obj_set_pos(iconPlayPause, 26, 115);
  }
  
  static lv_style_t stNameLabelStyle;
  lv_style_init(&stNameLabelStyle);
  lv_style_set_text_font(&stNameLabelStyle, &lv_font_montserrat_24);
  labelStationName = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelStationName, "Loading...");
  lv_obj_set_pos(labelStationName, 5, 65);
  lv_obj_set_size(labelStationName, 390, 73);
  lv_obj_add_style(labelStationName, &stNameLabelStyle, LV_PART_MAIN);
  lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);

  static lv_style_t stTitleLabelStyle;
  lv_style_init(&stTitleLabelStyle);
  lv_style_set_text_font(&stTitleLabelStyle, &lv_font_montserrat_18);
  labelTitle = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelTitle, "no data.. wait");
  lv_label_set_long_mode(labelTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_obj_add_style(labelTitle, &stTitleLabelStyle, LV_PART_MAIN);
  //lv_label_set_align(labelTitle, LV_LABEL_ALIGN_CENTER);
  lv_obj_set_pos(labelTitle, 90, 131);
  lv_obj_set_size(labelTitle, 323, 69); 


  /*Create an prev station button*/
  lv_obj_t * prevBtn = lv_imgbtn_create(lv_scr_act());
  lv_imgbtn_set_src(prevBtn, LV_IMGBTN_STATE_RELEASED, NULL, &prevStationBtn, NULL);
  lv_obj_add_style(prevBtn, &style_def, 0);
  lv_obj_add_style(prevBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(prevBtn, 85, 85);
  lv_obj_add_event_cb(prevBtn, eventPrevStationBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(prevBtn, 40, 213);

  /*Create an play and pause button*/
  lv_obj_t * playPauseBtn = lv_imgbtn_create(lv_scr_act());
  if (audio.isRunning())
    lv_imgbtn_set_src(playPauseBtn, LV_IMGBTN_STATE_RELEASED, NULL, &pauseBtn, NULL);
  else
    lv_imgbtn_set_src(playPauseBtn, LV_IMGBTN_STATE_RELEASED, NULL, &playBtn, NULL);
  lv_obj_add_style(playPauseBtn, &style_def, 0);
  lv_obj_add_style(playPauseBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(playPauseBtn, 100, 100);
  lv_obj_add_event_cb(playPauseBtn, eventPlayPauseBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(playPauseBtn, 159, 205);

  /*Create an next station button*/
  lv_obj_t * nextBtn = lv_imgbtn_create(lv_scr_act());
  lv_imgbtn_set_src(nextBtn, LV_IMGBTN_STATE_RELEASED, NULL, &nextStationBtn, NULL);
  lv_obj_add_style(nextBtn, &style_def, 0);
  lv_obj_add_style(nextBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(nextBtn, 85, 85);
  lv_obj_add_event_cb(nextBtn, eventNextStationBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(nextBtn, 293, 213);

  volDisplay = false;
  listDisplay = false;


  


  




}

void write_stationName(const char *sName){
  if (!labelStationName) return;
  lv_label_set_text_fmt(labelStationName, "%s", sName);
}

void write_title(const char *sName)
{
  if (!labelTitle) return;
  lv_label_set_text_fmt(labelTitle, "%s", sName);
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
  readConfig = new sdConfig();
  listStations = new listOfStations();
 
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
  
  if (wifiSetup())  
  {
    if (listStations->getCountOfStations() > 0)
    {
      currentStation = 0;
      audio.connecttohost(listStations->getUrlOfStation(listStations->getNameOfStations(currentStation)).c_str());
      //audio.connecttohost(stationsInfo[currentStation].url.c_str());
    }  else
    {
      audio_showstation("Radio Stations not found!");
    }
  }

  delay(500); 

}


void loop() {
  audio.loop();
  lv_timer_handler();  
}

void audio_showstation(const char *info){
    write_stationName(info);
}

void audio_showstreamtitle(const char *info){
    write_title(info);
}
