#include "uiApName.h"

void showApNameLabel()
{
  static lv_style_t stApNameLabelStyle;
  lv_style_init(&stApNameLabelStyle);
  lv_style_set_text_font(&stApNameLabelStyle, &ubuntu_24);
  labelApName = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelApName, "AP:");

  lv_obj_set_pos(labelApName, 24, 97);
  

  lv_obj_set_size(labelApName, 400, 43);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stApNameLabelStyle, colour);
  lv_obj_add_style(labelApName, &stApNameLabelStyle, LV_PART_MAIN);
}

void writeApName(const char *str)
{
    if (!labelApName) return;
    lv_label_set_text_fmt(labelApName, "AP: %s", str);
}
