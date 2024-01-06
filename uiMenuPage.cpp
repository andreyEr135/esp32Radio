#include "uiMenuPage.h"
#include "uiCurrentStationIcon.h"
#include "uiStationName.h"
#include "uiMenuBtn.h"



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
  static lv_style_t style;
  lv_style_init(&style);
  //lv_style_set_radius(&style, 5);
  lv_style_set_border_width(&style, 0);

  lv_color_t colourText;
  colourText = lv_color_hex(0xFFFFFF); 
  lv_color_t colourSelected;
  colourSelected = lv_color_hex(0x000458);    

  lv_color_t colour1;
  colour1 = lv_color_hex(0x000000);    
  lv_color_t colour2;
  colour2 = lv_color_hex(0x000746);    


  /*Make a gradient*/
  lv_style_set_bg_opa(&style, LV_OPA_COVER);
  static lv_grad_dsc_t grad;
  grad.dir = LV_GRAD_DIR_VER;
  grad.stops_count = 2;
  grad.stops[0].color = colour1;//lv_palette_lighten(LV_PALETTE_BLUE, 1);
  grad.stops[1].color = colour2;//lv_palette_main(LV_PALETTE_BLUE_GREY);
  /*Shift the gradient to the bottom*/
  grad.stops[0].frac  = 100;
  grad.stops[1].frac  = 240;

  lv_style_set_bg_grad(&style, &grad);

  /* Create page of list stations */
  pageStationsList = lv_obj_create(lv_scr_act()); /*Create a parent object on the current screen*/
  lv_obj_set_size(pageStationsList, 480, 267);
  lv_obj_set_pos(pageStationsList, 0, 0);
  lv_obj_add_style(pageStationsList, &style, 0);
  
  //lv_obj_add_style(pageStationsList, LV_OBJ_PART_MAIN, &style_bg);

  static lv_style_t stLabelStyle;
  lv_style_init(&stLabelStyle);
  lv_style_set_text_font(&stLabelStyle, &ubuntu_18);
  labelListTitle = lv_label_create(pageStationsList);
  lv_label_set_text_fmt(labelListTitle, "Список станций");
  lv_obj_set_pos(labelListTitle, 160, 0);
  lv_style_set_text_color(&stLabelStyle, colourText);
  lv_obj_add_style(labelListTitle, &stLabelStyle, LV_PART_MAIN);

  static lv_style_t styleMenu;
  lv_style_init(&styleMenu);
  lv_style_set_border_width(&styleMenu, 2);
  lv_style_set_bg_opa(&styleMenu, LV_OPA_TRANSP);
  lv_style_set_text_color(&styleMenu, colourText);

  static lv_style_t styleSelMenu;
  lv_style_init(&styleSelMenu);
  lv_style_set_border_width(&styleSelMenu, 2);
  lv_style_set_bg_color(&styleSelMenu, colourSelected);
  lv_style_set_text_color(&styleSelMenu, colourText);

  menuOfStations = lv_list_create(pageStationsList);
  lv_obj_set_size(menuOfStations, 435, 200);
  lv_obj_set_pos(menuOfStations, 0, 35);
  lv_obj_add_style(menuOfStations, &styleMenu, 0);
  
  lv_obj_t *list_btn;

  for (int i = 0; i < listStations->getCountOfStations(); i++)
  {    
    list_btn = lv_list_add_btn(menuOfStations, NULL, listStations->getNameOfStations(i).c_str());
    
    
    if (i == currentStation) lv_obj_add_style(list_btn, &styleSelMenu, 0);
    else lv_obj_add_style(list_btn, &styleMenu, 0);
    //lv_style_set_text_font(&menuOfStations, &ubuntu_18);
    lv_obj_add_event_cb(list_btn, eventListClickedHandler, LV_EVENT_CLICKED, NULL);
  }
  listDisplay = true;
  reshowMenuBtn();
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
  reshowMenuBtn();
}


