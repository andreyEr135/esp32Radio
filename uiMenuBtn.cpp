#include "uiMenuBtn.h"
#include "uiMenuPage.h"
#include "uiVolumePage.h"



static void eventMenuBtn(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
      if (!listDisplay) {
        if (volDisplay) HideVolume();
        CreateMenuOfStations();
        tickStationList = 0;
      }
      else 
      {
        HideMenuOfStations();
        tickStationList = 0;
      }
      reshowMenuBtn();
    }
}

void showMenuBtn()
{
  LV_IMG_DECLARE(listBtn);
  LV_IMG_DECLARE(listActiveBtn);
  menuBtn = lv_imgbtn_create(lv_scr_act());
  if (listDisplay) lv_imgbtn_set_src(menuBtn, LV_IMGBTN_STATE_RELEASED, NULL, &listActiveBtn, NULL);
  else lv_imgbtn_set_src(menuBtn, LV_IMGBTN_STATE_RELEASED, NULL, &listBtn, NULL);
  lv_obj_add_style(menuBtn, &style_def, 0);
  lv_obj_add_style(menuBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(menuBtn, 62, 34);
  lv_obj_add_event_cb(menuBtn, eventMenuBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(menuBtn, 207, 279);
}

void reshowMenuBtn()
{
  LV_IMG_DECLARE(listBtn);
  LV_IMG_DECLARE(listActiveBtn);
  if (listDisplay) lv_imgbtn_set_src(menuBtn, LV_IMGBTN_STATE_RELEASED, NULL, &listActiveBtn, NULL);
  else lv_imgbtn_set_src(menuBtn, LV_IMGBTN_STATE_RELEASED, NULL, &listBtn, NULL);
}


