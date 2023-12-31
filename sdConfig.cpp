#include "sdConfig.h"

sdConfig::sdConfig()
{
  configFile = "/config.json";
  sdInited = initSD();
}

bool sdConfig::initSD()
{
  hspi.begin(SD_CLK_PIN, SD_MISO_PIN, SD_MOSI_PIN, SD_CS_PIN);
  if(!SD.begin(SD_CS_PIN, hspi, SD_SPI_FREQ)){
    return false;
  } else 
  {
    uint8_t cardType = SD.cardType();
    if(cardType == CARD_NONE) return false;
  }
  return true;
}

bool sdConfig::readConfig()
{
  if (!sdInited) return false;
  DynamicJsonDocument config(1000);
  File dataFile = SD.open(configFile.c_str());
  DeserializationError error = deserializeJson(config, dataFile);

  if (error) 
  {
    errorStr = (String)error.f_str();
    return false;
  }
  

  /* READ SSID */
  const char* _str = config["ssid"];
  ssid = String(_str);

  /* READ PASSWORD */
  _str = config["password"];
  password = String(_str);

  /* READ WEATHER BLOCK */
  _str = config["weather"]["token"];
  weatherToken = String(_str);
  
  _str = config["weather"]["lat"];
  sscanf(_str, "%f", &weatherLat);
  _str = config["weather"]["lon"];
  sscanf(_str, "%f", &weatherLon);
  

  /* READ STATIONS-LIST */
  int cnt = atoi(config["stations"]["count"]);
  if (cnt > MAX_STATIONS) cnt = MAX_STATIONS - 1;
  for (int i = 0; i < cnt; i++)
  {
    char stationStr[255]; memset(stationStr, 0, sizeof(stationStr));
    sprintf(stationStr, "station%d", i);   
    
    const char* _name = config["stations"][stationStr]["name"];
    const char* _path = config["stations"][stationStr]["path"];
    listStations->addNewStation((String)_name, (String)_path);
  }     
  return true;
}

String sdConfig::GetError()
{
  return errorStr;   
}

String sdConfig::getWeatherToken()
{
  return weatherToken;

}
float sdConfig::getWeatherLat()
{
  return weatherLat;
}
float sdConfig::getWeatherLon()
{
  return weatherLon;
}