#include "batteryStatus.h"
#include <esp_adc_cal.h>
#include <esp32-hal-adc.h>

batteryStatus::batteryStatus()
{
  analog_pin = 13;
  adc_voltage = 0.0;            // Создаем переменную adc_voltage
  in_voltage = 0.0;             // Создаем переменную in_voltage
  R1 = 30000.0;                 // Задаем номинал резистора R1
  R2 = 7500.0;                  // Задаем номинал резистора R2
  ref_voltage = 3.3;            // Задаем опорное напряжение
  adc_value = 0;                  // Создаем переменную для хранения показаний

  analogReadResolution(12);
  pinMode(13, INPUT);  //GPIO4
  adcAttachPin(13);    //GPIO4
}


String batteryStatus::getBatteryVoltage()
{
  String res;
  adc_value = 0;
  for (int i = 0; i < 100; i++)
  {
    adc_value = adc_value + analogRead(analog_pin);
  }
  adc_value = adc_value / 100;

  
  adc_voltage = (adc_value * ref_voltage) / 4096.0; // Определение на входе АЦП
  
  in_voltage = adc_voltage / (R2/(R1+R2)) + 0.2 ;         // Расчет напряжения

  char str[10];
  sprintf(str, "%.2f", in_voltage);
  res = (String)str;
  
  return res;
}
