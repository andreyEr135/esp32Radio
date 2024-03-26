#include "uiApIp.h"

void showApIpLabel()
{
  static lv_style_t stApIpLabelStyle;
  lv_style_init(&stApIpLabelStyle);
  lv_style_set_text_font(&stApIpLabelStyle, &ubuntu_24);
  labelApIp = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelApIp, "IP:");

  lv_obj_set_pos(labelApIp, 32, 273);
  

  lv_obj_set_size(labelApIp, 390, 30);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stApIpLabelStyle, colour);
  lv_obj_add_style(labelApIp, &stApIpLabelStyle, LV_PART_MAIN);
}

void writeApIp(const char *str)
{
    if (!labelApIp) return;
    lv_label_set_text_fmt(labelApIp, "IP: %s", str);
}
