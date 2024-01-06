#include "uiVolumeInfo.h"

#include "uiVolumePage.h"
#include "uiMenuPage.h"
#include "uiMainPage.h"


void volumeInfoReDraw()
{
  LV_IMG_DECLARE(volumeBtn);
  LV_IMG_DECLARE(volumeMutedBtn);
  lv_color_t colour;

  if (volumeOut == 0) 
  {
    colour = lv_color_hex(0xA1A1A1);    
    lv_style_set_text_color(&stVolLabelStyle, colour);
    lv_obj_add_style(labelMainVolume, &stVolLabelStyle, LV_PART_MAIN);
    lv_imgbtn_set_src(volBtn, LV_IMGBTN_STATE_RELEASED, NULL, &volumeMutedBtn, NULL);
  }
  else 
  {
    if (prevVol == 0) 
    {
      colour = lv_color_hex(0xFFFFFF);    
      lv_style_set_text_color(&stVolLabelStyle, colour);
      lv_obj_add_style(labelMainVolume, &stVolLabelStyle, LV_PART_MAIN);
      lv_imgbtn_set_src(volBtn, LV_IMGBTN_STATE_RELEASED, NULL, &volumeBtn, NULL);
    }  
  }
  lv_label_set_text_fmt(labelMainVolume, "%d", volumeOut);
}


static void eventVolBtn(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        if (!mainWin) showMainPageAfterWeather();
        tickWeatherInfo = 0;
        if (volDisplay) {
          HideVolume();
          tickVolume = 0;
        } else
        {
          if (listDisplay) HideMenuOfStations();
          CreateVolumePage();
          tickVolume = 0;
        }
    }
}



void showVolumeBtn()
{
  LV_IMG_DECLARE(volumeBtn);
  LV_IMG_DECLARE(volumeMutedBtn);
  volBtn = lv_imgbtn_create(lv_scr_act());
  if (volumeOut == 0) lv_imgbtn_set_src(volBtn, LV_IMGBTN_STATE_RELEASED, NULL, &volumeMutedBtn, NULL);
  else lv_imgbtn_set_src(volBtn, LV_IMGBTN_STATE_RELEASED, NULL, &volumeBtn, NULL);
  lv_obj_add_style(volBtn, &style_def, 0);
  lv_obj_add_style(volBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(volBtn, 32, 33);
  lv_obj_add_event_cb(volBtn, eventVolBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(volBtn, 7, 279);
}

void showVolumeCount()
{
  lv_style_init(&stVolLabelStyle);
  lv_style_set_text_font(&stVolLabelStyle, &ubuntu_24);
  lv_color_t colour;
  if (volumeOut == 0) 
    colour = lv_color_hex(0xA1A1A1);    
  else
    colour = lv_color_hex(0xFFFFFF);    
  lv_style_set_text_color(&stVolLabelStyle, colour);

  labelMainVolume = lv_label_create(lv_scr_act());
  lv_label_set_text_fmt(labelMainVolume, "%d", volumeOut);
  
  lv_obj_set_pos(labelMainVolume, 45, 282);
  lv_obj_add_style(labelMainVolume, &stVolLabelStyle, LV_PART_MAIN);
}

void showVolumeBtnInfo()
{
  showVolumeBtn();
  showVolumeCount();
}