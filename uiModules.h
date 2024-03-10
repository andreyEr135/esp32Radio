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

// Version info
extern lv_obj_t *labelVersion;

// Battery state
//extern lv_obj_t *labelVoltage;
extern lv_obj_t *iconBattery;

// WiFi info
extern lv_obj_t *iconWifi;

// Volume info
//extern lv_obj_t *iconVolume;
extern lv_obj_t *volBtn;
extern lv_style_t stVolLabelStyle;
extern lv_obj_t *labelMainVolume;

// Volume page and elements
//extern bool volDisplay;
//extern int tickVolume;
extern lv_obj_t *pageVolume;
extern lv_obj_t *labelVolumeTitle;
extern lv_obj_t *sliderVolume;

// Menu page and elements
extern lv_obj_t *menuBtn;
//extern bool listDisplay;
extern int tickStationList;
extern lv_obj_t *pageStationsList;
extern lv_obj_t *labelListTitle;
extern lv_obj_t *menuOfStations;


// Scale radio icon
extern lv_obj_t *iconRadio;

// Current station icon info
extern lv_obj_t *currentIconRadio;




// Station name and track title labels
extern lv_obj_t *labelStationName;
extern lv_obj_t *labelTitle;

// Prev station button
extern lv_obj_t *prevBtn;

// Main page play and pause icon
extern lv_obj_t *iconPlayPause;

// Next station button
extern lv_obj_t *nextBtn;


// Main page play and pause button
extern lv_obj_t *playPauseBtn;

// Volume off button
extern lv_obj_t *volOffBtn; 

// WeatherInfo
extern lv_obj_t *labelCityName;
extern lv_obj_t *labelOblName;
extern lv_obj_t *labelTemp;
extern lv_obj_t *conditionIcon;
extern lv_obj_t *labelPressure;
extern lv_obj_t *iconHum;
extern lv_obj_t *labelHum;

// Timer
extern TaskHandle_t timerDispTask;
extern lv_timer_t *dispTimer;

#endif 