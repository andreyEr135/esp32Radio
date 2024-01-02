#include "uiVolumePage.h"


static void slider_event_cb(lv_event_t *e)
{
  LV_IMG_DECLARE(vol_off);
  LV_IMG_DECLARE(vol_offed);
  tickVolume = 0;
  // Refresh the text
  lv_label_set_text_fmt(labelVolumeTitle, "Громкость %" LV_PRId32, lv_slider_get_value(sliderVolume));
  volumeOut = lv_slider_get_value(sliderVolume);
  // lv_label_set_text_fmt(labelMainVolume, "Vol  %d", volumeOut);
  audio.setVolume(volumeOut);
  volumeInfoReDraw();

  if (volumeOut == 0)
  {
    lv_imgbtn_set_src(volOffBtn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_offed, NULL); 
  } else
  {
    if (prevVol == 0) 
    {
      lv_imgbtn_set_src(volOffBtn, LV_IMGBTN_STATE_RELEASED, NULL, &vol_off, NULL);
    }
  }
  prevVol = volumeOut;
}

void CreateVolumePage()
{
  pageVolume = lv_obj_create(lv_scr_act()); /*Create a parent object on the current screen*/
  lv_obj_set_size(pageVolume, 300, 90);
  lv_obj_align(pageVolume, LV_ALIGN_CENTER, 0, 0);

  sliderVolume = lv_slider_create(pageVolume);
  lv_obj_set_width(sliderVolume, 210);                                              // Set the width
  lv_obj_center(sliderVolume);                                                      // Align to the center of the parent (screen)
  lv_slider_set_range(sliderVolume, 0, 21);
  lv_slider_set_value(sliderVolume, volumeOut, LV_ANIM_ON);
  lv_obj_add_event_cb(sliderVolume, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL); // Assign an event function

  // Create a label above the slider
  static lv_style_t stVolPageLabelStyle;
  lv_style_init(&stVolPageLabelStyle);
  lv_style_set_text_font(&stVolPageLabelStyle, &ubuntu_18);

  labelVolumeTitle = lv_label_create(pageVolume);
  lv_obj_add_style(labelVolumeTitle, &stVolPageLabelStyle, LV_PART_MAIN);
  lv_label_set_text_fmt(labelVolumeTitle, "Громкость %" LV_PRId32, lv_slider_get_value(sliderVolume));
  lv_obj_align_to(labelVolumeTitle, sliderVolume, LV_ALIGN_OUT_TOP_MID, 0, -7); // Align top of the slider
  volDisplay = true;
}

void HideVolume()
{
  lv_obj_del(sliderVolume);
  lv_obj_del(labelVolumeTitle);
  lv_obj_del(pageVolume);
  sliderVolume = NULL;
  labelVolumeTitle = NULL;
  pageVolume = NULL;
  volDisplay = false;
}


