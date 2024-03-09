#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <string>

#include <Arduino.h>
#include "Audio.h"
#include <LovyanGFX.hpp>
#include "lvgl.h"
#include <lvgl.h>

#include "sdConfig.h"
#include "listOfStations.h"
#include "sysTime.h"
#include "weather.h"
#include "RadioMetadata.h"
#include "batteryStatus.h"



#define TIMEOUT_WIFI_CONNECT     10
#define TIMEOUT_VOLUME_PAGE      10
#define TIMEOUT_STATIONLIST_PAGE 10

extern int tickWeatherInfo;
#define TIMEOUT_WEATHER_INFO     1*60
#define TIMEOUT_WEATHER_GET      30*60


#define VALUE_MAX_LENGTH 255
#define KEY_MAX_LENGTH 255

#define MAX_STATIONS 32

#define SD_SPI_FREQ 1000000

// I2S Controller
#define I2S_LRCK 10 // 35
#define I2S_BCLK 12 //36
#define I2S_DOUT 11 //37

/* SD-Card Pins */
#define SD_CS_PIN 41
#define SD_MOSI_PIN 40 //MOSI
#define SD_CLK_PIN  39
#define SD_MISO_PIN 38 //MISO

// Screen info
#define screenWidth 480
#define screenHeight 320

// SD Config
class sdConfig;
extern sdConfig *readConfig;


// Flag of main window
extern bool mainWin;

// StationInfo structure and variables
extern bool listDisplay;
class listOfStations;
extern listOfStations *listStations;
extern int currentStation;

class RadioMetadata;
extern RadioMetadata *rdMetadata;

// Create Audio objects
extern bool audioPlaying;
extern Audio audio;

// WiFi settings
extern bool wifiConnect;
extern String ssid;
extern String password;

// SysTime
#define TIME_OFFSET 3
class sysTime;
extern sysTime *sTime;

// Weather
extern weather *weatherService;

// Battery status
class batteryStatus;
extern batteryStatus *battery;



// LGFX
class LGFX : public lgfx::LGFX_Device
{

    lgfx::Panel_ST7796 _panel_instance;
    lgfx::Bus_Parallel8 _bus_instance; // 8-bit parallel bus instance (ESP32 only)
    lgfx::Light_PWM _light_instance;
    lgfx::Touch_FT5x06 _touch_instance; // FT5206, FT5306, FT5406, FT6206, FT6236, FT6336, FT6436

  public:
    LGFX(void)
    {
      // Bus settings
      {
        auto cfg = _bus_instance.config();
        // 8-bit parallel bus settings
        // cfg.i2s_port = I2S_NUM_0;    // Select the I2S port to use (I2S_NUM_0 or I2S_NUM_1) (use ESP32's I2S LCD mode)
        cfg.freq_write = 20000000;              // Transmit clock (up to 20MHz, rounded to the value obtained by dividing 80MHz by an integer)
        cfg.pin_wr = 47;                        // WR
        cfg.pin_rd = -1;                        // RD
        cfg.pin_rs = 0;                         // RS(D/C)
        cfg.pin_d0 = 9;                         // D0
        cfg.pin_d1 = 46;                        // D1
        cfg.pin_d2 = 3;                         // D2
        cfg.pin_d3 = 8;                         // D3
        cfg.pin_d4 = 18;                        // D4
        cfg.pin_d5 = 17;                        // D5
        cfg.pin_d6 = 16;                        // D6
        cfg.pin_d7 = 15;                        // D7
        _bus_instance.config(cfg);              // Applies the set value to the bus
        _panel_instance.setBus(&_bus_instance); // Set the bus on the panel
      }

      // Display panel settings
      {
        auto cfg = _panel_instance.config();    // Get structure for display panel settings.

        cfg.pin_cs = -1;                        // CS
        cfg.pin_rst = 4;                        // RST
        cfg.pin_busy = -1;                      // BUSY

        // The following setting values â€‹â€‹are general initial values â€‹â€‹for each panel
        cfg.panel_width = 320;    // Actual displayable width
        cfg.panel_height = 480;   // Actual visible height
        cfg.offset_x = 0;         // Panel offset amount in X direction
        cfg.offset_y = 0;         // Panel offset amount in Y direction
        cfg.offset_rotation = 90; // Rotation direction value offset 0~7 (4~7 is upside down)
        cfg.dummy_read_pixel = 8; // Number of bits for dummy read before pixel readout
        cfg.dummy_read_bits = 1;  // Number of bits for dummy read before non-pixel data read
        cfg.readable = true;      // Set to true if data can be read
        cfg.invert = true;        // Set to true if the light/darkness of the panel is reversed
        cfg.rgb_order = false;    // Set to true if the panel's red and blue are swapped
        cfg.dlen_16bit = false;   // Set to true for panels that transmit data length in 16-bit units
        cfg.bus_shared = true;    // If the bus is shared with the SD card, set to True

        // Set the following only when the display is shifted with a driver with a variable number
        // of pixels, such as the ST7735 or ILI9163.
        //    cfg.memory_width     =   240;  // Maximum width supported by the driver IC
        //    cfg.memory_height    =   320;  // Maximum height supported by the driver IC

        _panel_instance.config(cfg);
      }

      // Backlight settings
      {
        auto cfg = _light_instance.config(); // Get structure for backlight settings

        cfg.pin_bl = 45;     // Pin number to which the backlight is connected
        cfg.invert = false;  // True to invert the brightness of the backlight
        cfg.freq = 44100;    // PWM frequency of backlight
        cfg.pwm_channel = 7; // PWM channel number to use

        _light_instance.config(cfg);
        _panel_instance.setLight(&_light_instance); // Set the backlight on display
      }

      // Touch control settings
      {
        auto cfg = _touch_instance.config();

        cfg.x_min = 0;           // Minimum X value (raw value)
        cfg.x_max = 319;         // Maximum X value (raw value)
        cfg.y_min = 0;           // Minimum Y value (raw value)
        cfg.y_max = 479;         // Maximum Y value (raw value)
        cfg.pin_int = 7;         // INT
        cfg.bus_shared = true;   // Set to True when using a common bus with the screen
        cfg.offset_rotation = 0; // Adjustment when the display and touch direction do not match (Set with a value of 0 to 7)
        // For I2C connection
        cfg.i2c_port = 1;        // Sel ect I2C to use (0 or 1)
        cfg.i2c_addr = 0x38;     // I2C device address number
        cfg.pin_sda = 6;         // SDA
        cfg.pin_scl = 5;         // SCL
        cfg.freq = 400000;       // Set I2C clock

        _touch_instance.config(cfg);
        _panel_instance.setTouch(&_touch_instance); // Set the touch screen on the panel
      }

      setPanel(&_panel_instance); // Set the panel to use
    }
};
extern LGFX tft;

// VolumeInfo
extern int tickVolume;
extern bool volDisplay;
extern int prevVol;
extern int volumeOut;

// Display
extern void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

// Sensor
extern void my_touch_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

extern int getPosOfCurrentRadio();



#endif 