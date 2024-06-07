#include "sdConfig.h"

sdConfig::sdConfig()
{
  configFile = "/config.json";
  sdInited = initSD();
  fileOpened = false;
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
  DynamicJsonDocument config(4000);
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
    const char* _meta = config["stations"][stationStr]["meta"];

    listStations->addNewStation((String)_name, (String)_path, (String)_meta);
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

bool sdConfig::writeWeatherInfo(String info)
{
  File weatherFile;

  if (SD.exists("/weather.txt")) SD.remove("/weather.txt");

  weatherFile = SD.open("/weather.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (weatherFile) {
    weatherFile.println(info.c_str());
    // close the file:
    weatherFile.close();
    return true;
  } else {
    return false;
  }
  return false;
}

String sdConfig::readWeatherInfo()
{
  String res = "";
  File weatherFile;
  weatherFile = SD.open("/weather.txt");

  // if the file opened okay, write to it:
  if (!weatherFile) return res;

  while (weatherFile.available()) {
    res = weatherFile.readString();
  }
  
  // close the file:
  weatherFile.close();
  return res;

}

bool sdConfig::writeCurrentStation(int id)
{
  File stationFile;

  if (SD.exists("/station.txt")) SD.remove("/station.txt");

  stationFile = SD.open("/station.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (stationFile) {
    stationFile.println(id);
    // close the file:
    stationFile.close();
    return true;
  } else {
    return false;
  }
  return false;

}

int sdConfig::readOldStation()
{
  int res = 0;
  File stationFile;
  stationFile = SD.open("/station.txt");

  // if the file opened okay, write to it:
  if (!stationFile) return res;

  while (stationFile.available()) {
    res = stationFile.readString().toInt();
  }
  
  // close the file:
  stationFile.close();
  return res;
}

bool sdConfig::writeCurrentVolume(int vol)
{
  File volumeFile;

  if (SD.exists("/volume.txt")) SD.remove("/volume.txt");

  volumeFile = SD.open("/volume.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (volumeFile) {
    volumeFile.println(vol);
    // close the file:
    volumeFile.close();
    return true;
  } else {
    return false;
  }
  return false;

}

int sdConfig::readOldVolume()
{
  int res = 10;
  File volumeFile;
  volumeFile = SD.open("/volume.txt");

  // if the file opened okay, write to it:
  if (!volumeFile) return res;

  while (volumeFile.available()) {
    res = volumeFile.readString().toInt();
  }
  
  // close the file:
  volumeFile.close();
  return res;
}

String sdConfig::getListOfFiles()
{
  String res = "";
  File root = SD.open("/");
  root.rewindDirectory();
  while(true) {
    File entry =  root.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    res += String("<tr><td>")+String(entry.name())+"</td>";
    int bytes = entry.size();
    String fsize = "";
    if (bytes < 1024)                     fsize = String(bytes)+" B";
    else if(bytes < (1024 * 1024))        fsize = String(bytes/1024.0,3)+" KB";
    else if(bytes < (1024 * 1024 * 1024)) fsize = String(bytes/1024.0/1024.0,3)+" MB";
    else                                  fsize = String(bytes/1024.0/1024.0/1024.0,3)+" GB";
    res += "<td>"+fsize+"</td>";
    res += "<td>";
    res += F("<FORM action='/' method='post'>"); 
    res += F("<button type='submit' name='download'"); 
    res += F("' value='"); res +="download_"+String(entry.name()); res +=F("'>Скачать</button>");
    res += "</td>";
    res += "<td>";
    res += F("<FORM action='/' method='post'>"); 
    res += F("<button type='submit' name='delete'"); 
    res += F("' value='"); res +="delete_"+String(entry.name()); res +=F("'>Удалить</button>");
    res += "</td>";
    res += "</tr>";
    //String("<a href='") + String(entry.name()) + String("'>") + String(entry.name()) + String("</a>") + String("</br>");
    entry.close();
  }
  return res;
}

File sdConfig::getFile(String path)
{
  return SD.open(path.c_str());
}


bool sdConfig::openFileForWrite(String name)
{
  fl = SD.open(name.c_str(), FILE_WRITE);
  if(!fl){
    audio_showstation("- failed to open file for writing");
    return false;
  }
  fileOpened = true;  
  return true;
}

bool sdConfig::writeToFile(uint8_t *buf, int size)
{
  if(fl.write(buf, size) != size){
    audio_showstation("- failed to write");
    return false;
  }
  return true;
}

bool sdConfig::closeFile()
{
  fl.close();
  fileOpened = false;  
  return true;
}

bool sdConfig::removeFile(String name)
{
  SD.remove(name);
  return true;
}

bool sdConfig::isFileOpened()
{
  return fileOpened;
}

bool sdConfig::sdCardIsInit()
{
  return sdInited;
}
