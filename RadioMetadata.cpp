#include "RadioMetadata.h"

//#include "globals.h"

using namespace std;

RadioMetadata::RadioMetadata()
{
  error = false;
}

String RadioMetadata::getMetadata(String station)
{
  String res = "";
  String str_copy;
  String str;
  bool founded = false;

  char buff[2500];

	String _url = (String)url + station + "/fmplay_current.json";

  WiFiClient client;
  client.stop();

  http.begin(client, host, 80, _url, true);
  int httpCode = http.GET();
  
  if (httpCode != 200)
  {
    error = true;
    errStr = "No metadata";
    return "no data, query err";
  }  
    
  ssize_t sz = http.getStream().available();  
  int c = http.getStream().readBytes(buff, ((sz > sizeof(buff)) ? sizeof(buff) : sz));
  str = (String)buff;

  if (str == "")
  {
    error = true;
    errStr = "No data";
    return "no data";
  }
 
  
  if (str.indexOf("metadata") > 0)
  {
      founded = false;
      str_copy = str;
      str_copy = str_copy.substring(str_copy.indexOf("metadata")+12);
      
      if (str_copy.indexOf('\"') > 0)
      {
          str_copy = str_copy.substring(0,str_copy.indexOf('\"'));
          res = str_copy;          
          str_copy = "";
          founded = true;
      }
  }


  http.end();
  return res;
}

bool RadioMetadata::isError()
{
  return error;
}

String RadioMetadata::getErrStr()
{
  return errStr;
}
