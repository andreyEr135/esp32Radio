#ifndef LISTOFSTATIONS_H
#define LISTOFSTATIONS_H

#include <iostream>
#include <string>

#include <Arduino.h>

#include "globals.h"

class listOfStations
{
  public:
    listOfStations();
    int getCountOfStations();
    bool addNewStation(String name, String url);
    String getUrlOfStation(String name);
    String getNameOfStations(int id);
    int getIdOfStation(String name);

    
  private:
    int countOfStations;

    struct _stationInfo {
      String name;
      String url;
    };
    struct _stationInfo stationsInfo[32];

  
};



#endif 