#include "uiApTitle.h"

void showApTitleLabel()
{
  static lv_style_t stApTitleLabelStyle;
  lv_style_init(&stApTitleLabelStyle);
  lv_style_set_text_font(&stApTitleLabelStyle, &ubuntu_24);
  lv_obj_t *labelApTitle = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelApTitle, "Точка доступа создана (конфигурация)");

  lv_obj_set_pos(labelApTitle, 90, 44);
  

  lv_obj_set_size(labelApTitle, 300, 43);
  lv_color_t colour;
  colour.ch.red   = 0xFF;
  colour.ch.green = 0xFF;
  colour.ch.blue  = 0xFF;
  lv_style_set_text_color(&stApTitleLabelStyle, colour);
  lv_obj_add_style(labelApTitle, &stApTitleLabelStyle, LV_PART_MAIN);
}