#include "uiWifiInfo.h"

void wifiInfoDraw()
{
  LV_IMG_DECLARE(wifiIcon);
  LV_IMG_DECLARE(wifiNoIcon);
  
  wifiConnect = (WiFi.status() == WL_CONNECTED);
  iconWifi = lv_img_create(lv_scr_act());
  if (wifiConnect)
  {
    lv_img_set_src(iconWifi, &wifiIcon);    
  } else
  {
    lv_img_set_src(iconWifi, &wifiNoIcon);
  }
  lv_obj_set_pos(iconWifi, 423, 3);  
}

void wifiInfoReDraw()
{
  LV_IMG_DECLARE(wifiIcon);
  LV_IMG_DECLARE(wifiNoIcon);

  if (WiFi.status() == WL_CONNECTED)
  {
    if (!wifiConnect) lv_img_set_src(iconWifi, &wifiIcon);    
  } else
  {
    if (wifiConnect) lv_img_set_src(iconWifi, &wifiNoIcon);
  }
  wifiConnect = (WiFi.status() == WL_CONNECTED);
}