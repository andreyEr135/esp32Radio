#include "uiTimeInfo.h"

void showTimeStr()
{
  static lv_style_t stTimeLabelStyle;
  lv_style_init(&stTimeLabelStyle);
  lv_style_set_text_font(&stTimeLabelStyle, &ubuntu_16);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stTimeLabelStyle, colour);

  labelTime = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelTime, sTime->getTime().c_str());
  lv_obj_set_pos(labelTime, 5, 3);
  
  lv_obj_add_style(labelTime, &stTimeLabelStyle, LV_PART_MAIN);
}

void reshowTimeStr()
{
  lv_label_set_text_fmt(labelTime, sTime->getTime().c_str());
}