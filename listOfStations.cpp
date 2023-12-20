#include "listOfStations.h"

listOfStations::listOfStations()
{
  countOfStations = 0;
}

int listOfStations::getCountOfStations()
{
  return countOfStations;
}
    
bool listOfStations::addNewStation(String name, String url)
{
  _stationInfo station;
  station.name = name;
  station.url = url;
  stationsInfo[countOfStations] = station;
  countOfStations++;
  return true;
}
    
String listOfStations::getUrlOfStation(String name)
{
  if (name == "") return "";
  for (int i = 0; i < countOfStations; i++)
    if (strcmp(stationsInfo[i].name.c_str(), name.c_str()) == 0) return stationsInfo[i].url;
}
    
String listOfStations::getNameOfStations(int id)
{
  if (id > countOfStations) return "";
  return stationsInfo[id].name;
}

int listOfStations::getIdOfStation(String name)
{
  for (int i = 0; i < countOfStations; i++)
    if (strcmp(stationsInfo[i].name.c_str(), name.c_str()) == 0) return i;
  return -1;
}
