#include "uiVersionLabel.h"

void showVersionStr()
{
  static lv_style_t stVersionLabelStyle;
  lv_style_init(&stVersionLabelStyle);
  lv_style_set_text_font(&stVersionLabelStyle, &ubuntu_14);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stVersionLabelStyle, colour);

  static lv_obj_t *labelVersion = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelVersion, "v2.0");
  lv_obj_set_pos(labelVersion, 215, 3);
  
  lv_obj_add_style(labelVersion, &stVersionLabelStyle, LV_PART_MAIN);
}