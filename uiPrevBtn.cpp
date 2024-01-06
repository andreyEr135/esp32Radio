#include "uiPrevBtn.h"
#include "uiStationName.h"
#include "uiCurrentStationIcon.h"



static void eventPrevStationBtn(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
      tickWeatherInfo = 0;
      currentStation--;
      if (currentStation < 0) currentStation = listStations->getCountOfStations() - 1;
      writeStationName(listStations->getNameOfStations(currentStation).c_str());
      reshowCurrentRadioStationIcon();
      audio.connecttohost(listStations->getUrlOfStation(listStations->getNameOfStations(currentStation)).c_str());
    }
}

void showPrevBtn()
{
  LV_IMG_DECLARE(prevStationBtn);
  prevBtn = lv_imgbtn_create(lv_scr_act());
  lv_imgbtn_set_src(prevBtn, LV_IMGBTN_STATE_RELEASED, NULL, &prevStationBtn, NULL);
  lv_obj_add_style(prevBtn, &style_def, 0);
  lv_obj_add_style(prevBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(prevBtn, 52, 53);
  lv_obj_add_event_cb(prevBtn, eventPrevStationBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(prevBtn, 24, 200);
}

void hidePrevBtn()
{
  lv_obj_del(prevBtn);
  prevBtn = NULL;
}