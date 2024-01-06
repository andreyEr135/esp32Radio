#include "uiConditionIcon.h"

void conditionIconDraw()
{
  LV_IMG_DECLARE(clear);
  LV_IMG_DECLARE(partlyCloudy);
  LV_IMG_DECLARE(cloudy);
  LV_IMG_DECLARE(overcast);
  LV_IMG_DECLARE(lightRain);
  LV_IMG_DECLARE(rain);
  LV_IMG_DECLARE(heavyRain);
  LV_IMG_DECLARE(showers);
  LV_IMG_DECLARE(wetSnow);
  LV_IMG_DECLARE(lightSnow);
  LV_IMG_DECLARE(snow);
  LV_IMG_DECLARE(snowShowers);
  LV_IMG_DECLARE(hail);
  LV_IMG_DECLARE(thunderStorm);
  LV_IMG_DECLARE(thunderStormRain);
  LV_IMG_DECLARE(thunderStormHail);
  LV_IMG_DECLARE(unknown);
  
  conditionIcon = lv_img_create(lv_scr_act());

  String cond = "";
  if (!weatherService) 
  {
    lv_img_set_src(conditionIcon, &unknown); 
  } else
  {
    cond = weatherService->getCondition();
    if (cond == "clear") lv_img_set_src(conditionIcon, &clear); 
    else if (cond == "partly-cloudy") lv_img_set_src(conditionIcon, &partlyCloudy); 
    else if (cond == "cloudy") lv_img_set_src(conditionIcon, &cloudy); 
    else if (cond == "overcast") lv_img_set_src(conditionIcon, &overcast); 
    else if (cond == "light-rain") lv_img_set_src(conditionIcon, &lightRain); 
    else if (cond == "rain") lv_img_set_src(conditionIcon, &rain); 
    else if (cond == "heavy-rain") lv_img_set_src(conditionIcon, &heavyRain); 
    else if (cond == "showers") lv_img_set_src(conditionIcon, &showers); 
    else if (cond == "wet-snow") lv_img_set_src(conditionIcon, &wetSnow); 
    else if (cond == "light-snow") lv_img_set_src(conditionIcon, &lightSnow); 
    else if (cond == "snow") lv_img_set_src(conditionIcon, &snow); 
    else if (cond == "snow-showers") lv_img_set_src(conditionIcon, &snowShowers); 
    else if (cond == "hail") lv_img_set_src(conditionIcon, &hail); 
    else if (cond == "thunderstorm") lv_img_set_src(conditionIcon, &thunderStorm); 
    else if (cond == "thunderstorm-with-rain") lv_img_set_src(conditionIcon, &thunderStormRain); 
    else if (cond == "thunderstorm-with-hail") lv_img_set_src(conditionIcon, &thunderStormHail); 
    else lv_img_set_src(conditionIcon, &unknown); 
  }
  if (cond == "clear") lv_obj_set_size(conditionIcon, 80, 80);
  else lv_obj_set_size(conditionIcon, 82, 56);
  lv_obj_set_pos(conditionIcon, 23, 175);  
}

void conditionIconHide()
{
  lv_obj_del(conditionIcon);
  conditionIcon = NULL;
}



void conditionIconReDraw()
{
  LV_IMG_DECLARE(clear);
  LV_IMG_DECLARE(partlyCloudy);
  LV_IMG_DECLARE(cloudy);
  LV_IMG_DECLARE(overcast);
  LV_IMG_DECLARE(lightRain);
  LV_IMG_DECLARE(rain);
  LV_IMG_DECLARE(heavyRain);
  LV_IMG_DECLARE(showers);
  LV_IMG_DECLARE(wetSnow);
  LV_IMG_DECLARE(lightSnow);
  LV_IMG_DECLARE(snow);
  LV_IMG_DECLARE(snowShowers);
  LV_IMG_DECLARE(hail);
  LV_IMG_DECLARE(thunderStorm);
  LV_IMG_DECLARE(thunderStormRain);
  LV_IMG_DECLARE(thunderStormHail);
  LV_IMG_DECLARE(unknown);

  String cond = "";
  if (!weatherService) 
  {
    lv_img_set_src(conditionIcon, &unknown); 
  } else
  {
    cond = weatherService->getCondition();
    if (cond == "clear") lv_img_set_src(conditionIcon, &clear); 
    else if (cond == "partly-cloudy") lv_img_set_src(conditionIcon, &partlyCloudy); 
    else if (cond == "cloudy") lv_img_set_src(conditionIcon, &cloudy); 
    else if (cond == "overcast") lv_img_set_src(conditionIcon, &overcast); 
    else if (cond == "light-rain") lv_img_set_src(conditionIcon, &lightRain); 
    else if (cond == "rain") lv_img_set_src(conditionIcon, &rain); 
    else if (cond == "heavy-rain") lv_img_set_src(conditionIcon, &heavyRain); 
    else if (cond == "showers") lv_img_set_src(conditionIcon, &showers); 
    else if (cond == "wet-snow") lv_img_set_src(conditionIcon, &wetSnow); 
    else if (cond == "light-snow") lv_img_set_src(conditionIcon, &lightSnow); 
    else if (cond == "snow") lv_img_set_src(conditionIcon, &snow); 
    else if (cond == "snow-showers") lv_img_set_src(conditionIcon, &snowShowers); 
    else if (cond == "hail") lv_img_set_src(conditionIcon, &hail); 
    else if (cond == "thunderstorm") lv_img_set_src(conditionIcon, &thunderStorm); 
    else if (cond == "thunderstorm-with-rain") lv_img_set_src(conditionIcon, &thunderStormRain); 
    else if (cond == "thunderstorm-with-hail") lv_img_set_src(conditionIcon, &thunderStormHail); 
    else lv_img_set_src(conditionIcon, &unknown); 
  }
  if (cond == "clear") lv_obj_set_size(conditionIcon, 80, 80);
  else lv_obj_set_size(conditionIcon, 82, 56);
}