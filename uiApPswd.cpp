#include "uiApPswd.h"

void showApPswdLabel()
{
  static lv_style_t stApPswdLabelStyle;
  lv_style_init(&stApPswdLabelStyle);
  lv_style_set_text_font(&stApPswdLabelStyle, &ubuntu_24);
  labelApPswd = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelApPswd, "PSWD:");

  lv_obj_set_pos(labelApPswd, 24, 197);
  

  lv_obj_set_size(labelApPswd, 400, 43);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stApPswdLabelStyle, colour);
  lv_obj_add_style(labelApPswd, &stApPswdLabelStyle, LV_PART_MAIN);
}

void writeApPswd(const char *str)
{
    if (!labelApPswd) return;
    lv_label_set_text_fmt(labelApPswd, "PSWD: %s", str);
}

