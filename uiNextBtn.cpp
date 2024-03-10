#include "uiNextBtn.h"
#include "uiStationName.h"
#include "uiTitleLabel.h"
#include "uiCurrentStationIcon.h"




static void eventNextStationBtn(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
      tickWeatherInfo = 0;
      currentStation++;
      if (currentStation > listStations->getCountOfStations() - 1) currentStation = 0;
      writeStationName(listStations->getNameOfStations(currentStation).c_str());
      reshowCurrentRadioStationIcon();      
      audio.connecttohost(listStations->getUrlOfStation(listStations->getNameOfStations(currentStation)).c_str());
      readConfig->writeCurrentStation(currentStation);

      String metaStation = listStations->getMetadataName(currentStation);
      if (metaStation == "") writeTitle("");
      else {
        writeTitle(rdMetadata->getMetadata(metaStation).c_str());
      }  
    }
}

void showNextBtn()
{
  LV_IMG_DECLARE(nextStationBtn);
  nextBtn = lv_imgbtn_create(lv_scr_act());
  lv_imgbtn_set_src(nextBtn, LV_IMGBTN_STATE_RELEASED, NULL, &nextStationBtn, NULL);
  lv_obj_add_style(nextBtn, &style_def, 0);
  lv_obj_add_style(nextBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(nextBtn, 52, 53);
  lv_obj_add_event_cb(nextBtn, eventNextStationBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(nextBtn, 387, 200);
}

void hideNextBtn()
{
  lv_obj_del(nextBtn);
  nextBtn = NULL;
}