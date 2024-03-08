#include "uiVoltageLabel.h"

void showVoltageLabel()
{
  static lv_style_t stVoltageLabelStyle;
  lv_style_init(&stVoltageLabelStyle);
  lv_style_set_text_font(&stVoltageLabelStyle, &ubuntu_16);
  labelVoltage = lv_label_create(lv_scr_act());
  //lv_label_set_text_fmt(labelVoltage, "---V");
  if (!battery) lv_label_set_text_fmt(labelVoltage, "---V");
  else  lv_label_set_text_fmt(labelVoltage, "%sV", battery->getBatteryVoltage().c_str());
  
  lv_obj_set_pos(labelVoltage, 320, 1);
  //lv_obj_set_size(labelTemp, 88, 47);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stVoltageLabelStyle, colour);
  lv_obj_add_style(labelVoltage, &stVoltageLabelStyle, LV_PART_MAIN);
  //lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);
}

void writeVoltage()
{
  if (!labelVoltage) return;
  if (!battery) lv_label_set_text_fmt(labelVoltage, "---V");
  else  lv_label_set_text_fmt(labelVoltage, "%sV", battery->getBatteryVoltage().c_str());
 // String volt = weatherService->getTemperature();
 // lv_label_set_text_fmt(labelVoltage, "%sV", temp.c_str());
}