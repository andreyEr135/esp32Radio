#include "uiCityName.h"

void showNameCityLabel()
{
  static lv_style_t stNameCityLabelStyle;
  lv_style_init(&stNameCityLabelStyle);
  lv_style_set_text_font(&stNameCityLabelStyle, &ubuntu_24);
  labelCityName = lv_label_create(lv_scr_act());
  if (weatherService) lv_label_set_text_fmt(labelCityName, "%s", weatherService->getCity().c_str());
  else lv_label_set_text_fmt(labelCityName, "---");
  lv_obj_set_pos(labelCityName, 110, 160);
  lv_obj_set_size(labelCityName, 168, 67);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stNameCityLabelStyle, colour);
  lv_obj_add_style(labelCityName, &stNameCityLabelStyle, LV_PART_MAIN);
  //lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);
}

void hideNameCityLabel()
{
  lv_obj_del(labelCityName);
  labelCityName = NULL;
}

void writeCityName()
{
  if (!labelCityName) return;
  lv_label_set_text_fmt(labelCityName, "%s", weatherService->getCity().c_str());
}