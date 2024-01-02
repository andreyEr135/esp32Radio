#include "uiPlayPauseIcon.h"

void showPlayPauseIcon()
{
  LV_IMG_DECLARE(playIcon);
  LV_IMG_DECLARE(pauseIcon);

  iconPlayPause = lv_img_create(lv_scr_act());
  if (audio.isRunning() == true) 
  {
    lv_img_set_src(iconPlayPause, &playIcon);   
  }
  else
  {
    lv_img_set_src(iconPlayPause, &pauseIcon);
  }
  lv_obj_set_pos(iconPlayPause, 453, 143);
}

void playPauseIconChangeState(bool played)
{
  LV_IMG_DECLARE(playIcon);
  LV_IMG_DECLARE(pauseIcon);
    
  if (audioPlaying != played)
  {
    if (played)
    {
      lv_img_set_src(iconPlayPause, &playIcon);
    }
    else
    {
      lv_img_set_src(iconPlayPause, &pauseIcon);
    }  
  }
}

