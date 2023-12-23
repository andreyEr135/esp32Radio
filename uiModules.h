#ifndef UIMODULES_H
#define UIMODULES_H

#include <iostream>
#include <string>

#include <Arduino.h>

#include "lvgl.h"

// Create an instance of the prepared class
#include <lvgl.h>

// styles
extern lv_style_t style_def;
extern lv_style_t style_pr;

// Time info
extern lv_obj_t *labelTime;

// WiFi info
extern lv_obj_t *iconWifi;

// Volume info
extern lv_obj_t *iconVolume;
extern lv_style_t stVolLabelStyle;
extern lv_obj_t *labelMainVolume;

// Volume page and elements
extern bool volDisplay;
extern int tickVolume;
extern lv_obj_t *pageVolume;
extern lv_obj_t *labelVolumeTitle;
extern lv_obj_t *sliderVolume;

// Menu page and elements
extern bool listDisplay;
extern int tickStationList;
extern lv_obj_t *pageStationsList;
extern lv_obj_t *labelListTitle;
extern lv_obj_t *menuOfStations;



// Station name and track title labels
extern lv_obj_t *labelStationName;
extern lv_obj_t *labelTitle;

// Main page play and pause icon
extern lv_obj_t *iconPlayPause;

// Main page play and pause button
extern lv_obj_t *playPauseBtn;

// Volume off button
extern lv_obj_t *volOffBtn; 

// Timer
extern TaskHandle_t timerDispTask;
extern lv_timer_t *dispTimer;

#endif 