#include "uiModules.h"

// styles
lv_style_t style_def;
lv_style_t style_pr;


// Time info
lv_obj_t *labelTime;

// Version info
lv_obj_t *labelVersion;

// WiFi info
lv_obj_t *iconWifi;

// Volume label
//lv_obj_t *iconVolume;
lv_obj_t *volBtn;
lv_style_t stVolLabelStyle;
lv_obj_t *labelMainVolume;


// Volume page and elements
//bool volDisplay;
//int tickVolume;
lv_obj_t *pageVolume;
lv_obj_t *labelVolumeTitle;
lv_obj_t *sliderVolume;

// Menu page and elements
lv_obj_t *menuBtn;
//bool listDisplay;
int tickStationList;
lv_obj_t *pageStationsList;
lv_obj_t *labelListTitle;
lv_obj_t *menuOfStations;

// Scale radio icon
lv_obj_t *iconRadio;

// Current station icon info
lv_obj_t *currentIconRadio;



// Station name and track title labels
lv_obj_t *labelStationName;
lv_obj_t *labelTitle;

// Main page play and pause icon
lv_obj_t *iconPlayPause;

// Prev station button
lv_obj_t *prevBtn;

// Main page play and pause button
lv_obj_t *playPauseBtn;

// Next station button
lv_obj_t *nextBtn;

// Volume off button
lv_obj_t *volOffBtn;

// WeatherInfo
lv_obj_t *labelCityName;
lv_obj_t *labelOblName;
lv_obj_t *labelTemp;
lv_obj_t *conditionIcon;
lv_obj_t *labelPressure;
lv_obj_t *iconHum;
lv_obj_t *labelHum;

// Timer
TaskHandle_t timerDispTask;
lv_timer_t *dispTimer;

 