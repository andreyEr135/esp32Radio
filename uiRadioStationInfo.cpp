#include "uiRadioStationInfo.h"


void showRadioStationInfo()
{
  LV_IMG_DECLARE(radioStations);

  iconRadio = lv_img_create(lv_scr_act());
  lv_img_set_src(iconRadio, &radioStations);   
  lv_obj_set_pos(iconRadio, 7, 100);
}

void hideRadioStationInfo()
{
  lv_obj_del(iconRadio);
  iconRadio = NULL;
}