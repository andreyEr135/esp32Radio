#include "uiStationName.h"

void showNameStationLabel()
{
  static lv_style_t stNameLabelStyle;
  lv_style_init(&stNameLabelStyle);
  lv_style_set_text_font(&stNameLabelStyle, &ubuntu_24);
  labelStationName = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelStationName, "Loading...");

  if (mainWin) lv_obj_set_pos(labelStationName, 20, 35);
  else lv_obj_set_pos(labelStationName, 20, 51);

  lv_obj_set_size(labelStationName, 456, 43);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stNameLabelStyle, colour);
  lv_obj_add_style(labelStationName, &stNameLabelStyle, LV_PART_MAIN);
  //lv_label_set_long_mode(labelStationName, LV_LABEL_LONG_SCROLL_CIRCULAR);
}

void reShowNameStationLabel()
{
  if (mainWin) lv_obj_set_pos(labelStationName, 20, 35);
  else lv_obj_set_pos(labelStationName, 20, 51);
}

void writeStationName(const char *str)
{
    if (!labelStationName) return;
    lv_label_set_text_fmt(labelStationName, "%s", str);
}

