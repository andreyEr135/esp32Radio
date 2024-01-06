#include "uiHumInfo.h"


void showIconHum()
{
  LV_IMG_DECLARE(hum);
  
  iconHum = lv_img_create(lv_scr_act());

  lv_img_set_src(iconHum, &hum); 
  
  lv_obj_set_size(iconHum, 19, 20);
  lv_obj_set_pos(iconHum, 320, 234);  

}

void showLabelHum()
{
  static lv_style_t stHumLabelStyle;
  lv_style_init(&stHumLabelStyle);
  lv_style_set_text_font(&stHumLabelStyle, &ubuntu_20);
  labelHum = lv_label_create(lv_scr_act());
  if (weatherService) lv_label_set_text_fmt(labelHum, "%s", weatherService->getHumidity().c_str());
  else lv_label_set_text_fmt(labelHum, "---");
  lv_obj_set_pos(labelHum, 347, 231);
  lv_obj_set_size(labelHum, 55, 27);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stHumLabelStyle, colour);
  lv_obj_add_style(labelHum, &stHumLabelStyle, LV_PART_MAIN);
  //lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);
}


void showHumInfo()
{
  showIconHum();
  showLabelHum();
}

void hideHumInfo()
{
  lv_obj_del(iconHum);
  iconHum = NULL;
  lv_obj_del(labelHum);
  labelHum = NULL;
}

void reShowHumInfo()
{
  if (!labelHum) return;
  String hum = weatherService->getHumidity();
  lv_label_set_text_fmt(labelHum, "%s", hum.c_str());
}