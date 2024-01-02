#include "uiModules.h"

// styles
lv_style_t style_def;
lv_style_t style_pr;


// Time info
lv_obj_t *labelTime;

// WiFi info
lv_obj_t *iconWifi;

// Volume label
//lv_obj_t *iconVolume;
lv_obj_t *volBtn;
lv_style_t stVolLabelStyle;
lv_obj_t *labelMainVolume;


// Volume page and elements
bool volDisplay;
int tickVolume;
lv_obj_t *pageVolume;
lv_obj_t *labelVolumeTitle;
lv_obj_t *sliderVolume;

// Menu page and elements
lv_obj_t *menuBtn;
bool listDisplay;
int tickStationList;
lv_obj_t *pageStationsList;
lv_obj_t *labelListTitle;
lv_obj_t *menuOfStations;

// Current station icon info
lv_obj_t *currentIconRadio;



// Station name and track title labels
lv_obj_t *labelStationName;
lv_obj_t *labelTitle;

// Main page play and pause icon
lv_obj_t *iconPlayPause;

// Main page play and pause button
lv_obj_t *playPauseBtn;

// Volume off button
lv_obj_t *volOffBtn;

// Timer
TaskHandle_t timerDispTask;
lv_timer_t *dispTimer;

 