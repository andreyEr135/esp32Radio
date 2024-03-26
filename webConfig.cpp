#include "webConfig.h"

#include "uiApName.h"
#include "uiApPswd.h"
#include "uiApIp.h"

ESP32WebServer *server;


String webpage = ""; //String to save the html code

void append_page_header() {
  webpage  = F("<!DOCTYPE html><html lang='ru-RU'>");
  webpage += F("<head>");
  webpage += F("<title>Интернет радио</title>"); // NOTE: 1em = 16px
  webpage += F("<meta name='viewport' content='user-scalable=yes,initial-scale=1.0,width=device-width' charset='UTF-8'>");
  webpage += F("<style>");//From here style:
  webpage += F("body{max-width:65%;margin:0 auto;font-family:arial;font-size:100%;}");
  webpage += F("ul{list-style-type:none;padding:0;border-radius:0em;overflow:hidden;background-color:#d90707;font-size:1em;}");
  webpage += F("li{float:left;border-radius:0em;border-right:0em solid #bbb;}");
  webpage += F("li a{color:white; display: block;border-radius:0.375em;padding:0.44em 0.44em;text-decoration:none;font-size:100%}");
  webpage += F("li a:hover{background-color:#e86b6b;border-radius:0em;font-size:100%}");
  webpage += F("h1{color:white;border-radius:0em;font-size:1.5em;padding:0.2em 0.2em;background:#d90707;}");
  webpage += F("h2{color:blue;font-size:0.8em;}");
  webpage += F("h3{font-size:0.8em;}");
  webpage += F("table{font-family:arial,sans-serif;font-size:0.9em;border-collapse:collapse;width:85%;}"); 
  webpage += F("th,td {border:0.06em solid #dddddd;text-align:left;padding:0.3em;border-bottom:0.06em solid #dddddd;}"); 
  webpage += F("tr:nth-child(odd) {background-color:#eeeeee;}");
  webpage += F(".rcorners_n {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:20%;color:white;font-size:75%;}");
  webpage += F(".rcorners_m {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:50%;color:white;font-size:75%;}");
  webpage += F(".rcorners_w {border-radius:0.5em;background:#558ED5;padding:0.3em 0.3em;width:70%;color:white;font-size:75%;}");
  webpage += F(".column{float:left;width:50%;height:45%;}");
  webpage += F(".row:after{content:'';display:table;clear:both;}");
  webpage += F("*{box-sizing:border-box;}");
  webpage += F("a{font-size:75%;}");
  webpage += F("p{font-size:75%;}");
  webpage += F("</style></head><body><h1>Интернет радио</h1>");
  webpage += F("<ul>");
  webpage += F("<li><a href='/'>Список файлов</a></li>"); //Menu bar with commands
  webpage += F("<li><a href='/upload'>Загрузка файла</a></li>"); 
  webpage += F("</ul>");
}
//Saves repeating many lines of code for HTML page footers
void append_page_footer()
{ 
  webpage += F("</body></html>");
}


//SendHTML_Header
void SendHTML_Header()
{
  server->sendHeader("Cache-Control", "no-cache, no-store, must-revalidate"); 
  server->sendHeader("Pragma", "no-cache"); 
  server->sendHeader("Expires", "-1"); 
  server->setContentLength(CONTENT_LENGTH_UNKNOWN); 
  server->send(200, "text/html", ""); //Empty content inhibits Content-length header so we have to close the socket ourselves. 
  append_page_header();
  server->sendContent(webpage);
  webpage = "";
}

//SendHTML_Content
void SendHTML_Content()
{
  server->sendContent(webpage);
  webpage = "";
}

//SendHTML_Stop
void SendHTML_Stop()
{
  server->sendContent("");
  server->client().stop(); //Stop is needed because no content length was sent
}


bool loadFromSDCARD(String path){
  path.toLowerCase();
  String dataType = "text/plain";
  if(path.endsWith("/")) path += "index.htm";

  if(path.endsWith(".src")) path = path.substring(0, path.lastIndexOf("."));
  else if(path.endsWith(".jpg")) dataType = "image/jpeg";
  else if(path.endsWith(".txt")) dataType = "text/plain";
  else if(path.endsWith(".zip")) dataType = "application/zip";  
  File dataFile = readConfig->getFile(path);

  if (!dataFile)
    return false;

  if (server->streamFile(dataFile, dataType) != dataFile.size()) {
   
  }

  dataFile.close();
  return true;
}


void handleRoot() {
  //Action acording to post, dowload or delete, by MC 2022
  if (server->args() > 0 ) //Arguments were received, ignored if there are not arguments
  { 
    String Order = server->arg(0);
    
    if (Order.indexOf("download_")>=0)
    {
      Order.remove(0,9);
      loadFromSDCARD(String("/") + Order);
    }

    if ((server->arg(0)).indexOf("delete_")>=0)
    {
      Order.remove(0,7);
      readConfig->removeFile(String("/") + Order);
    }
  }


  SendHTML_Header();    
  webpage += F("<table align='center'>");
  webpage += F("<tr><th>Название файла</th><th>Размер</th></tr>");
  webpage += readConfig->getListOfFiles();
  webpage += F("</table>");
  SendHTML_Content();
  append_page_footer();
  SendHTML_Content();
  SendHTML_Stop();   //Stop is needed because no content length was sent
}



void handleNotFound(){
  if(loadFromSDCARD(server->uri())) return;
  String message = "SDCARD Not Detected\n\n";
  message += "URI: ";
  message += server->uri();
  message += "\nMethod: ";
  message += (server->method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server->args();
  message += "\n";
  for (uint8_t i=0; i<server->args(); i++){
    message += " NAME:"+server->argName(i) + "\n VALUE:" + server->arg(i) + "\n";
  }
  server->send(404, "text/plain", message);
}





//ReportCouldNotCreateFile
void ReportCouldNotCreateFile(String target)
{
  SendHTML_Header();
  webpage += F("<h3>Неудалось создать файл</h3>"); 
  webpage += F("<a href='/"); webpage += target + "'>[Назад]</a><br><br>";
  append_page_footer();
  SendHTML_Content();
  SendHTML_Stop();
}

//File size conversion
String file_size(int bytes)
{
  String fsize = "";
  if (bytes < 1024)                 fsize = String(bytes)+" B";
  else if(bytes < (1024*1024))      fsize = String(bytes/1024.0,3)+" KB";
  else if(bytes < (1024*1024*1024)) fsize = String(bytes/1024.0/1024.0,3)+" MB";
  else                              fsize = String(bytes/1024.0/1024.0/1024.0,3)+" GB";
  return fsize;
}

//Upload a new file to the Filing system
void handleFileUpload()
{ 
  HTTPUpload& uploadfile = server->upload(); //See https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer/srcv
                                            //For further information on 'status' structure, there are other reasons such as a failed transfer that could be used
  if(uploadfile.status == UPLOAD_FILE_START)
  {
    String filename = uploadfile.filename;
    if(!filename.startsWith("/")) filename = "/"+filename;
    readConfig->removeFile(filename);
    if (!readConfig->openFileForWrite(filename)) return;
    filename = String();
  }
  else if (uploadfile.status == UPLOAD_FILE_WRITE)
  {
    if(readConfig->isFileOpened()) 
      if (!readConfig->writeToFile(uploadfile.buf, uploadfile.currentSize)) return;
  } 
  else if (uploadfile.status == UPLOAD_FILE_END)
  {
    if(readConfig->isFileOpened())          //If the file was successfully created
    {   
      readConfig->closeFile();                                 
      webpage = "";
      append_page_header();
      webpage += F("<h3>Файл успешно загружен</h3>"); 
      webpage += F("<h2>Название файла: "); webpage += uploadfile.filename+"</h2>";
      webpage += F("<h2>Размер: "); webpage += file_size(uploadfile.totalSize) + "</h2><br><br>"; 
      webpage += F("<a href='/'>[Назад]</a><br><br>");
      append_page_footer();
      server->send(200,"text/html",webpage);
    } 
    else
    {
      ReportCouldNotCreateFile("upload");
    }
  }
}



//Upload a file to the SD
void File_Upload()
{
  append_page_header();
  webpage += F("<h3>Выберите файл для загрузки</h3>"); 
  webpage += F("<FORM action='/fupload' method='post' enctype='multipart/form-data'>");
  webpage += F("<input class='buttons' style='width:25%' type='file' name='fupload' id = 'fupload' value=''>");
  webpage += F("<button class='buttons' style='width:10%' type='submit'>Загрузить</button><br><br>");
  webpage += F("<a href='/'>[Назад]</a><br><br>");
  append_page_footer();
  server->send(200, "text/html",webpage);
}



bool serverStart()
{
  WiFi.softAP("WiFiRadio", "12345678"); //Network and password for the access point genereted by ESP32

  server = new ESP32WebServer(80);
  server->on("/", handleRoot);
  server->onNotFound(handleNotFound);

  server->on("/upload",   File_Upload);
  server->on("/fupload",  HTTP_POST,[](){ server->send(200);}, handleFileUpload);
  server->begin();

  writeApName("WiFiRadio");
  writeApPswd("12345678");
  writeApIp(WiFi.softAPIP().toString().c_str());
  return true;
}


