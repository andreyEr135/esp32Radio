#include "uiMenuPage.h"
#include "uiCurrentStationIcon.h"
#include "uiStationName.h"



static void eventListClickedHandler(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * btn = lv_event_get_target(e);
  if(code == LV_EVENT_CLICKED) {
    currentStation = listStations->getIdOfStation((String)lv_list_get_btn_text(menuOfStations, btn));
    writeStationName(listStations->getNameOfStations(currentStation).c_str());
    reshowCurrentRadioStationIcon();
    audio.connecttohost(listStations->getUrlOfStation((String)lv_list_get_btn_text(menuOfStations, btn)).c_str());   
    HideMenuOfStations();
  }
}

void CreateMenuOfStations()
{
  /* Create page of list stations */
  pageStationsList = lv_obj_create(lv_scr_act()); /*Create a parent object on the current screen*/
  lv_obj_set_size(pageStationsList, 390, 300);
  lv_obj_set_pos(pageStationsList, 10, 10);

  static lv_style_t stLabelStyle;
  lv_style_init(&stLabelStyle);
  lv_style_set_text_font(&stLabelStyle, &ubuntu_18);
  labelListTitle = lv_label_create(pageStationsList);
  lv_label_set_text_fmt(labelListTitle, "Список станций");
  lv_obj_set_pos(labelListTitle, 90, 0);
  lv_obj_add_style(labelListTitle, &stLabelStyle, LV_PART_MAIN);

  menuOfStations = lv_list_create(pageStationsList);
  lv_obj_set_size(menuOfStations, 355, 220);
  lv_obj_set_pos(menuOfStations, 0, 35);
  
  lv_obj_t *list_btn;

  for (int i = 0; i < listStations->getCountOfStations(); i++)
  {    
    list_btn = lv_list_add_btn(menuOfStations, NULL, listStations->getNameOfStations(i).c_str());
    //lv_style_set_text_font(&menuOfStations, &ubuntu_18);
    lv_obj_add_event_cb(list_btn, eventListClickedHandler, LV_EVENT_CLICKED, NULL);
  }
  listDisplay = true;
}

void HideMenuOfStations()
{
  lv_obj_del(labelListTitle);
  lv_obj_del(menuOfStations);
  lv_obj_del(pageStationsList);
  labelListTitle = NULL;
  menuOfStations = NULL;
  pageStationsList = NULL;
  listDisplay = false;
}


