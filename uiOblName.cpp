#include "uiOblName.h"

void showNameOblLabel()
{
  static lv_style_t stNameOblLabelStyle;
  lv_style_init(&stNameOblLabelStyle);
  lv_style_set_text_font(&stNameOblLabelStyle, &ubuntu_18);
  labelOblName = lv_label_create(lv_scr_act());
  if (weatherService) lv_label_set_text_fmt(labelOblName, "%s", weatherService->getOblast().c_str());
  else lv_label_set_text_fmt(labelOblName, "---");
  lv_obj_set_pos(labelOblName, 110, 205);
  lv_obj_set_size(labelOblName, 138, 67);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stNameOblLabelStyle, colour);
  lv_obj_add_style(labelOblName, &stNameOblLabelStyle, LV_PART_MAIN);
  //lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);
}

void hideNameOblLabel()
{
  lv_obj_del(labelOblName);
  labelOblName = NULL;
}

void writeOblName()
{
  if (!labelOblName) return;
  lv_label_set_text_fmt(labelOblName, "%s", weatherService->getOblast().c_str());
}