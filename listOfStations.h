#ifndef LISTOFSTATIONS_H
#define LISTOFSTATIONS_H

#include <iostream>
#include <string>

#include <Arduino.h>

#define MAX_STATIONS 32

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
    struct _stationInfo stationsInfo[MAX_STATIONS];

  
};



#endif 