#include "uiCurrentStationIcon.h"



void showCurrentRadioStationIcon()
{
  LV_IMG_DECLARE(radioCurrentIcon);

  currentIconRadio = lv_img_create(lv_scr_act());
  lv_img_set_src(currentIconRadio, &radioCurrentIcon);   
  lv_obj_set_pos(currentIconRadio, 15, 94);
  
}

void reshowCurrentRadioStationIcon()
{  
  lv_obj_set_pos(currentIconRadio, getPosOfCurrentRadio(), 94);
}

void hideCurrentRadioStationIcon()
{
  lv_obj_del(currentIconRadio);
  currentIconRadio = NULL;
}