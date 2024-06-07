#include "uiBatteryIcon.h"


void batteryStatusDraw()
{
  LV_IMG_DECLARE(battery_0);
  LV_IMG_DECLARE(battery_25);
  LV_IMG_DECLARE(battery_50);
  LV_IMG_DECLARE(battery_75);
  LV_IMG_DECLARE(battery_100);
  
  int charge = 0;
  if (battery) charge = battery->getBatteryCharge();

  iconBattery = lv_img_create(lv_scr_act());
  if ((charge >= 0) && (charge < 15))
    lv_img_set_src(iconBattery, &battery_0);    
  else if ((charge >= 15) && (charge < 40))
    lv_img_set_src(iconBattery, &battery_25);    
  else if ((charge >= 40) && (charge < 60))
    lv_img_set_src(iconBattery, &battery_50);    
  else if ((charge >= 60) && (charge < 80))
    lv_img_set_src(iconBattery, &battery_75);    
  else if (charge >= 80)
    lv_img_set_src(iconBattery, &battery_100);    
  
  lv_obj_set_pos(iconBattery, 447, 3);  
}

void batteryStatusRedraw()
{
  LV_IMG_DECLARE(battery_0);
  LV_IMG_DECLARE(battery_25);
  LV_IMG_DECLARE(battery_50);
  LV_IMG_DECLARE(battery_75);
  LV_IMG_DECLARE(battery_100);
  int charge = 0;
  if (battery) charge = battery->getBatteryCharge();

  if ((charge >= 0) && (charge < 15))
    lv_img_set_src(iconBattery, &battery_0);    
  else if ((charge >= 15) && (charge < 40))
    lv_img_set_src(iconBattery, &battery_25);    
  else if ((charge >= 40) && (charge < 60))
    lv_img_set_src(iconBattery, &battery_50);    
  else if ((charge >= 60) && (charge < 80))
    lv_img_set_src(iconBattery, &battery_75);    
  else if (charge >= 80)
    lv_img_set_src(iconBattery, &battery_100);   

}