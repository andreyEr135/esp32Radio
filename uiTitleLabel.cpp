#include "uiTitleLabel.h"

void showTitleInfoLabel()
{
  static lv_style_t stTitleLabelStyle;
  lv_style_init(&stTitleLabelStyle);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_font(&stTitleLabelStyle, &ubuntu_18);
  labelTitle = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelTitle, "no data.. wait");
  //lv_label_set_long_mode(labelTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_style_set_text_color(&stTitleLabelStyle, colour);
  lv_obj_add_style(labelTitle, &stTitleLabelStyle, LV_PART_MAIN);
  if (mainWin)
  {
    lv_obj_set_pos(labelTitle, 20, 137);
  } else
  {
    lv_obj_set_pos(labelTitle, 20, 104);
  }
  lv_obj_set_size(labelTitle, 430, 49); 
}

void reShowTitleInfoLabel()
{
  if (mainWin)
  {
    lv_obj_set_pos(labelTitle, 20, 137);
  } else
  {
    lv_obj_set_pos(labelTitle, 20, 104);
  }
}

void writeTitle(const char *str)
{
    if (!labelStationName) return;
    lv_label_set_text_fmt(labelTitle, "%s", str);
}