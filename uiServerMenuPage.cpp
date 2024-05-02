#include "uiServerMenuPage.h"
#include "otaServer.h"
#include "webConfig.h"

#include "uiApPage.h"
#include "uiOtaPage.h"



static void eventListClickedHandler(lv_event_t * e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * btn = lv_event_get_target(e);
  if(code == LV_EVENT_CLICKED) {
    String buttonName = (String)lv_list_get_btn_text(menuOfServersMode, btn);
    if (buttonName == "Конфигурация")
    {
      HideServerMenu();
      showApPage();
      serverStart();
    } else if (buttonName == "OTA режим")
    {
      HideServerMenu();
      showOtaPage();
      serverOtaStart();
    }  
  }
}

void CreateServerMenu()
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
  pageServerMenu = lv_obj_create(lv_scr_act()); /*Create a parent object on the current screen*/
  lv_obj_set_size(pageServerMenu, 480, 267);
  lv_obj_set_pos(pageServerMenu, 0, 0);
  lv_obj_add_style(pageServerMenu, &style, 0);
  
  //lv_obj_add_style(pageServerMenu, LV_OBJ_PART_MAIN, &style_bg);

  static lv_style_t stLabelStyle;
  lv_style_init(&stLabelStyle);
  lv_style_set_text_font(&stLabelStyle, &ubuntu_18);
  labelServerModeTitle = lv_label_create(pageServerMenu);
  lv_label_set_text_fmt(labelServerModeTitle, "Режим настройки");
  lv_obj_set_pos(labelServerModeTitle, 160, 0);
  lv_style_set_text_color(&stLabelStyle, colourText);
  lv_obj_add_style(labelServerModeTitle, &stLabelStyle, LV_PART_MAIN);

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

  menuOfServersMode = lv_list_create(pageStationsList);
  lv_obj_set_size(menuOfServersMode, 435, 200);
  lv_obj_set_pos(menuOfServersMode, 0, 35);
  lv_obj_add_style(menuOfServersMode, &styleMenu, 0);
  
  lv_obj_t *list_btn;

  
  list_btn = lv_list_add_btn(menuOfServersMode, NULL, "Конфигурация");
  lv_obj_add_style(list_btn, &styleMenu, 0);
  lv_obj_add_event_cb(list_btn, eventListClickedHandler, LV_EVENT_CLICKED, NULL);

  list_btn = lv_list_add_btn(menuOfServersMode, NULL, "OTA режим");
  lv_obj_add_style(list_btn, &styleMenu, 0);
  lv_obj_add_event_cb(list_btn, eventListClickedHandler, LV_EVENT_CLICKED, NULL);
}

void HideServerMenu()
{
  lv_obj_del(labelServerModeTitle);
  lv_obj_del(menuOfServersMode);
  lv_obj_del(pageServerMenu);
  labelServerModeTitle = NULL;
  menuOfServersMode = NULL;
  pageServerMenu = NULL;
}


