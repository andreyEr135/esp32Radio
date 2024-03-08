#ifndef BATTERYSTATUS_H
#define BATTERYSTATUS_H

#include <iostream>
#include <string>

#include <Arduino.h>

class batteryStatus
{
  public:
    batteryStatus();
    String getBatteryVoltage();

    
  private:
    int analog_pin;
    float adc_voltage;            // Создаем переменную adc_voltage
    float in_voltage;             // Создаем переменную in_voltage
    float R1;                 // Задаем номинал резистора R1
    float R2;                  // Задаем номинал резистора R2
    float ref_voltage;            // Задаем опорное напряжение
    int adc_value;                  // Создаем переменную для хранения показаний

  
};



#endif 