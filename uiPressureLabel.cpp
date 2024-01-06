#include "uiPressureLabel.h"

void showPressureLabel()
{
  static lv_style_t stPressureLabelStyle;
  lv_style_init(&stPressureLabelStyle);
  lv_style_set_text_font(&stPressureLabelStyle, &ubuntu_20);
  labelPressure = lv_label_create(lv_scr_act());
  if (weatherService) lv_label_set_text_fmt(labelPressure, "%s мм.рт.ст.", weatherService->getPressure().c_str());
  else lv_label_set_text_fmt(labelPressure, "--- мм.рт.ст.");
  
  lv_obj_set_pos(labelPressure, 295, 197);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stPressureLabelStyle, colour);
  lv_obj_add_style(labelPressure, &stPressureLabelStyle, LV_PART_MAIN);
  //lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);
}

void hidePressureLabel()
{
  lv_obj_del(labelPressure);
  labelPressure = NULL;
}

void writePressure()
{
  if (!labelPressure) return;
  String pressure = weatherService->getPressure();
  lv_label_set_text_fmt(labelPressure, "%s мм.рт.ст.", pressure.c_str());
}