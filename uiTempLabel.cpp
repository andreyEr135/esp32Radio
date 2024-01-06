#include "uiTempLabel.h"

void showTempLabel()
{
  static lv_style_t stTempLabelStyle;
  lv_style_init(&stTempLabelStyle);
  if (mainWin) lv_style_set_text_font(&stTempLabelStyle, &ubuntu_16);
  else lv_style_set_text_font(&stTempLabelStyle, &ubuntu_36);
  labelTemp = lv_label_create(lv_scr_act());
  if (weatherService) lv_label_set_text_fmt(labelTemp, "%s°C", weatherService->getTemperature().c_str());
  else lv_label_set_text_fmt(labelTemp, "---°C");
  
  if (mainWin) lv_obj_set_pos(labelTemp, 400, 1);
  else lv_obj_set_pos(labelTemp, 314, 155);
  //lv_obj_set_size(labelTemp, 88, 47);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stTempLabelStyle, colour);
  lv_obj_add_style(labelTemp, &stTempLabelStyle, LV_PART_MAIN);
  //lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);
}

void reShowTempLabel()
{
  static lv_style_t stTempLabelStyle;
  lv_style_init(&stTempLabelStyle);
  if (mainWin) lv_style_set_text_font(&stTempLabelStyle, &ubuntu_16);
  else lv_style_set_text_font(&stTempLabelStyle, &ubuntu_36);
  if (weatherService)
  {
    String temp = weatherService->getTemperature();
    lv_label_set_text_fmt(labelTemp, "%s°C", temp.c_str());
  } else lv_label_set_text_fmt(labelTemp, "---°C");
  if (mainWin) lv_obj_set_pos(labelTemp, 400, 1);
  else lv_obj_set_pos(labelTemp, 314, 155);
  //lv_obj_set_size(labelTemp, 88, 47);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stTempLabelStyle, colour);
  lv_obj_add_style(labelTemp, &stTempLabelStyle, LV_PART_MAIN);
  //lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);
}

void writeTemp()
{
  if (!labelTemp) return;
  String temp = weatherService->getTemperature();
  lv_label_set_text_fmt(labelTemp, "%s°C", temp.c_str());
}