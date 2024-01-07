#include "uiVolOffBtn.h"
#include "uiVolumeInfo.h"
#include "uiMainPage.h"

static void eventVolOffBtn(lv_event_t * e)
{
    static int oldVolume;
    LV_IMG_DECLARE(vol_off);
    LV_IMG_DECLARE(vol_offed);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
      if (volumeOut == 0)
      {
        volumeOut = oldVolume;
        if (sliderVolume) lv_slider_set_value(sliderVolume, volumeOut, LV_ANIM_ON);
        if (labelVolumeTitle) lv_label_set_text_fmt(labelVolumeTitle, "Громкость %" LV_PRId32, lv_slider_get_value(sliderVolume));
        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_off, NULL);
      } else
      {
        oldVolume = volumeOut;
        volumeOut = 0;
        if (sliderVolume) lv_slider_set_value(sliderVolume, volumeOut, LV_ANIM_ON);
        if (labelVolumeTitle) lv_label_set_text_fmt(labelVolumeTitle, "Громкость %" LV_PRId32, lv_slider_get_value(sliderVolume));
        lv_imgbtn_set_src(btn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_offed, NULL);
      }
      audio.setVolume(volumeOut);
      if (!mainWin) showMainPageAfterWeather();
      tickWeatherInfo = 0;
      volumeInfoReDraw();
      readConfig->writeCurrentVolume(volumeOut);
      prevVol = volumeOut;
    }
}

void showVolumeOffBtn()
{
  LV_IMG_DECLARE(vol_off);
  LV_IMG_DECLARE(vol_offed);
  volOffBtn = lv_imgbtn_create(lv_scr_act());
  if (volumeOut == 0) lv_imgbtn_set_src(volOffBtn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_offed, NULL);
  else lv_imgbtn_set_src(volOffBtn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_off, NULL);
  lv_obj_add_style(volOffBtn, &style_def, 0);
  lv_obj_add_style(volOffBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_set_size(volOffBtn, 38, 37);
  lv_obj_add_event_cb(volOffBtn, eventVolOffBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(volOffBtn, 429, 277);
}

