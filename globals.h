#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <string>

#include <Arduino.h>

#define VALUE_MAX_LENGTH 255
#define KEY_MAX_LENGTH 255

#define MAX_STATIONS 32

struct _stationInfo {
  String name;
  String url;
};
extern _stationInfo stationInfo;

extern struct _stationInfo stationsInfo[MAX_STATIONS];



//extern String *listOfStations[MAX_STATIONS];

#endif 