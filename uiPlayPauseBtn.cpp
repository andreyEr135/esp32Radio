#include "uiPlayPauseBtn.h"
#include "uiPlayPauseIcon.h"


static void eventPlayPauseBtn(lv_event_t * e)
{
    LV_IMG_DECLARE(playBtn);
    LV_IMG_DECLARE(pauseBtn);
   // LV_IMG_DECLARE(playIcon);
   // LV_IMG_DECLARE(pauseIcon);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
      tickWeatherInfo = 0;
      audio.pauseResume();
      playPauseBtnChangeState(audio.isRunning());
    }
}

void showPlayPauseBtn()
{
  LV_IMG_DECLARE(playBtn);
  LV_IMG_DECLARE(pauseBtn);
  playPauseBtn = lv_imgbtn_create(lv_scr_act());
  if (audio.isRunning())
  {
    lv_imgbtn_set_src(playPauseBtn, LV_IMGBTN_STATE_RELEASED, NULL, &pauseBtn, NULL);
    lv_obj_set_size(playPauseBtn, 42, 53);
  }
  else
  {
    lv_imgbtn_set_src(playPauseBtn, LV_IMGBTN_STATE_RELEASED, NULL, &playBtn, NULL);
    lv_obj_set_size(playPauseBtn, 40, 53);
  }
  lv_obj_add_style(playPauseBtn, &style_def, 0);
  lv_obj_add_style(playPauseBtn, &style_pr, LV_STATE_PRESSED);
  lv_obj_add_event_cb(playPauseBtn, eventPlayPauseBtn, LV_EVENT_ALL, NULL);
  lv_obj_set_pos(playPauseBtn, 215, 200);
}

void hidePlayPauseBtn()
{
  lv_obj_del(playPauseBtn);
  playPauseBtn = NULL;
}

void playPauseBtnChangeState(bool played)
{
  LV_IMG_DECLARE(playBtn);
  LV_IMG_DECLARE(pauseBtn);
    
  if (audioPlaying != played)
  {
    if (played)
    {
      lv_imgbtn_set_src(playPauseBtn, LV_IMGBTN_STATE_RELEASED, NULL, &pauseBtn, NULL);  
      lv_obj_set_size(playPauseBtn, 42, 53); 
    }
    else
    {
      lv_imgbtn_set_src(playPauseBtn, LV_IMGBTN_STATE_RELEASED, NULL, &playBtn, NULL);
      lv_obj_set_size(playPauseBtn, 40, 53);
    }
    playPauseIconChangeState(played);
    audioPlaying = played;      
  }
}

