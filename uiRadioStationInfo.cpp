#include "uiRadioStationInfo.h"


void showRadioStationInfo()
{
  LV_IMG_DECLARE(radioStations);

  lv_obj_t *iconRadio = lv_img_create(lv_scr_act());
  lv_img_set_src(iconRadio, &radioStations);   
  lv_obj_set_pos(iconRadio, 7, 100);
}