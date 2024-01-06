#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

//#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
//#else
//    #include "lvgl/lvgl.h"
//#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_HUM
#define LV_ATTRIBUTE_IMG_HUM
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_HUM uint8_t hum_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x40, 0x77, 0xbf, 0x77, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x7f, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x10, 0x77, 0xaf, 0x77, 0xff, 0x77, 0xff, 0x77, 0xcf, 0x77, 0xff, 0x77, 0xff, 0x77, 0xaf, 0x77, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x20, 0x77, 0xcf, 0x77, 0xff, 0x77, 0xff, 0x77, 0x70, 0x00, 0x00, 0x77, 0x80, 0x77, 0xff, 0x77, 0xff, 0x77, 0xdf, 0x77, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x20, 0x77, 0xdf, 0x77, 0xff, 0x77, 0xef, 0x77, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x50, 0x77, 0xef, 0x77, 0xff, 0x77, 0xdf, 0x77, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x77, 0x20, 0x77, 0xdf, 0x77, 0xff, 0x77, 0xef, 0x77, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x30, 0x77, 0xef, 0x77, 0xff, 0x77, 0xdf, 0x77, 0x10, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x77, 0xbf, 0x77, 0xff, 0x77, 0xef, 0x77, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x30, 0x77, 0xef, 0x77, 0xff, 0x77, 0xbf, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x77, 0x7f, 0x77, 0xff, 0x77, 0xff, 0x77, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x60, 0x77, 0xff, 0x77, 0xff, 0x77, 0x70, 0x00, 0x00, 
  0x77, 0x20, 0x77, 0xff, 0x77, 0xff, 0x77, 0x90, 0x00, 0x00, 0x77, 0xbf, 0x77, 0xff, 0x77, 0xaf, 0x77, 0x10, 0x00, 0x00, 0x00, 0x00, 0x77, 0x20, 0x77, 0xbf, 0x77, 0x20, 0x00, 0x00, 0x77, 0x90, 0x77, 0xff, 0x77, 0xef, 0x77, 0x10, 
  0x77, 0x9f, 0x77, 0xff, 0x77, 0xdf, 0x77, 0x20, 0x77, 0x30, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0x40, 0x00, 0x00, 0x77, 0x40, 0x77, 0xef, 0x77, 0xff, 0x77, 0xcf, 0x00, 0x00, 0x77, 0x10, 0x77, 0xef, 0x77, 0xff, 0x77, 0x80, 
  0x77, 0xcf, 0x77, 0xff, 0x77, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x77, 0xaf, 0x77, 0xff, 0x77, 0xbf, 0x77, 0x10, 0x77, 0x6f, 0x77, 0xff, 0x77, 0xff, 0x77, 0xdf, 0x77, 0x20, 0x00, 0x00, 0x00, 0x00, 0x77, 0x90, 0x77, 0xff, 0x77, 0xdf, 
  0x77, 0xff, 0x77, 0xff, 0x77, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x8f, 0x77, 0xff, 0x77, 0xff, 0x77, 0xaf, 0x77, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x60, 0x77, 0xff, 0x77, 0xff, 
  0x77, 0xff, 0x77, 0xff, 0x77, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x10, 0x77, 0xaf, 0x77, 0xff, 0x77, 0xff, 0x77, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x70, 0x77, 0xff, 0x77, 0xff, 
  0x77, 0xcf, 0x77, 0xff, 0x77, 0x90, 0x00, 0x00, 0x00, 0x00, 0x77, 0x20, 0x77, 0xdf, 0x77, 0xff, 0x77, 0xff, 0x77, 0x70, 0x77, 0x10, 0x77, 0xbf, 0x77, 0xff, 0x77, 0xaf, 0x00, 0x00, 0x00, 0x00, 0x77, 0x9f, 0x77, 0xff, 0x77, 0xcf, 
  0x77, 0x80, 0x77, 0xff, 0x77, 0xef, 0x77, 0x10, 0x00, 0x00, 0x77, 0xcf, 0x77, 0xff, 0x77, 0xef, 0x77, 0x40, 0x00, 0x00, 0x77, 0x40, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0x30, 0x77, 0x20, 0x77, 0xdf, 0x77, 0xff, 0x77, 0x90, 
  0x77, 0x10, 0x77, 0xef, 0x77, 0xff, 0x77, 0x9f, 0x00, 0x00, 0x77, 0x20, 0x77, 0xbf, 0x77, 0x20, 0x00, 0x00, 0x00, 0x00, 0x77, 0x10, 0x77, 0xaf, 0x77, 0xff, 0x77, 0xbf, 0x00, 0x00, 0x77, 0xaf, 0x77, 0xff, 0x77, 0xef, 0x77, 0x20, 
  0x00, 0x00, 0x77, 0x70, 0x77, 0xff, 0x77, 0xff, 0x77, 0xaf, 0x77, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x10, 0x77, 0x9f, 0x77, 0xff, 0x77, 0xff, 0x77, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x77, 0x80, 0x77, 0xff, 0x77, 0xff, 0x77, 0xdf, 0x77, 0x8f, 0x77, 0x40, 0x77, 0x10, 0x00, 0x00, 0x77, 0x10, 0x77, 0x40, 0x77, 0x7f, 0x77, 0xef, 0x77, 0xff, 0x77, 0xff, 0x77, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x40, 0x77, 0xdf, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0xff, 0x77, 0xdf, 0x77, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x50, 0x77, 0xa0, 0x77, 0xcf, 0x77, 0xff, 0x77, 0xff, 0x77, 0xef, 0x77, 0xdf, 0x77, 0x9f, 0x77, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x40, 0x1e, 0x5d, 0xbf, 0x1e, 0x5d, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x7f, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x55, 0x10, 0x1e, 0x5d, 0xaf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xcf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xaf, 0x1e, 0x55, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x20, 0x1e, 0x5d, 0xcf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x70, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x80, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xdf, 0x1d, 0x5d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x20, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x50, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xdf, 0x1d, 0x5d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x20, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x30, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xdf, 0x1e, 0x55, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0xbf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x30, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1e, 0x5d, 0x7f, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x60, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x70, 0x00, 0x00, 0x00, 
  0x1d, 0x5d, 0x20, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x90, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0xbf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xaf, 0x1e, 0x55, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x20, 0x1e, 0x5d, 0xbf, 0x1d, 0x5d, 0x20, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x90, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xef, 0x1e, 0x55, 0x10, 
  0x1e, 0x5d, 0x9f, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0x20, 0x1d, 0x5d, 0x30, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1d, 0x5d, 0x40, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x40, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xcf, 0x00, 0x00, 0x00, 0x1e, 0x55, 0x10, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x80, 
  0x1e, 0x5d, 0xcf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0xaf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xbf, 0x1e, 0x55, 0x10, 0x1e, 0x5d, 0x6f, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x90, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xdf, 
  0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x8f, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xaf, 0x1e, 0x55, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x60, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 
  0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x55, 0x10, 0x1e, 0x5d, 0xaf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x70, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 
  0x1e, 0x5d, 0xcf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x20, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x70, 0x1c, 0x55, 0x10, 0x1e, 0x5d, 0xbf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xaf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x9f, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xcf, 
  0x1e, 0x5d, 0x80, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xef, 0x1e, 0x55, 0x10, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0xcf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xef, 0x1d, 0x5d, 0x40, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x40, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x30, 0x1d, 0x5d, 0x20, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x90, 
  0x1e, 0x55, 0x10, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x9f, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x20, 0x1e, 0x5d, 0xbf, 0x1e, 0x5d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x55, 0x10, 0x1e, 0x5d, 0xaf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xbf, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0xaf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0x20, 
  0x00, 0x00, 0x00, 0x1e, 0x5d, 0x70, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xaf, 0x1d, 0x5d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x55, 0x10, 0x1e, 0x5d, 0x9f, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x70, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x80, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0x8f, 0x1d, 0x5d, 0x40, 0x1c, 0x55, 0x10, 0x00, 0x00, 0x00, 0x1c, 0x55, 0x10, 0x1d, 0x5d, 0x40, 0x1e, 0x5d, 0x7f, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x5d, 0x40, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xdf, 0x1d, 0x5d, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x5d, 0x50, 0x1e, 0x5d, 0xa0, 0x1e, 0x5d, 0xcf, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xff, 0x1e, 0x5d, 0xef, 0x1e, 0x5d, 0xdf, 0x1e, 0x5d, 0x9f, 0x1d, 0x5d, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x40, 0x5d, 0x1e, 0xbf, 0x5d, 0x1e, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x7f, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x1c, 0x10, 0x5d, 0x1e, 0xaf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xcf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xaf, 0x55, 0x1e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x20, 0x5d, 0x1e, 0xcf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x70, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x80, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xdf, 0x5d, 0x1d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x20, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x50, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xdf, 0x5d, 0x1d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x20, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x30, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xdf, 0x55, 0x1e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0xbf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x30, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x5d, 0x1e, 0x7f, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x60, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x70, 0x00, 0x00, 0x00, 
  0x5d, 0x1d, 0x20, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x90, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0xbf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xaf, 0x55, 0x1e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x20, 0x5d, 0x1e, 0xbf, 0x5d, 0x1d, 0x20, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x90, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xef, 0x55, 0x1e, 0x10, 
  0x5d, 0x1e, 0x9f, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0x20, 0x5d, 0x1d, 0x30, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1d, 0x40, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x40, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xcf, 0x00, 0x00, 0x00, 0x55, 0x1e, 0x10, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x80, 
  0x5d, 0x1e, 0xcf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0xaf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xbf, 0x55, 0x1e, 0x10, 0x5d, 0x1e, 0x6f, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x90, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xdf, 
  0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x8f, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xaf, 0x55, 0x1e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x60, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 
  0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x1c, 0x10, 0x5d, 0x1e, 0xaf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x70, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 
  0x5d, 0x1e, 0xcf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x20, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x70, 0x55, 0x1c, 0x10, 0x5d, 0x1e, 0xbf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xaf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x9f, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xcf, 
  0x5d, 0x1e, 0x80, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xef, 0x55, 0x1e, 0x10, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0xcf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xef, 0x5d, 0x1d, 0x40, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x40, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x30, 0x5d, 0x1d, 0x20, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x90, 
  0x55, 0x1e, 0x10, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x9f, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x20, 0x5d, 0x1e, 0xbf, 0x5d, 0x1e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x1e, 0x10, 0x5d, 0x1e, 0xaf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xbf, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0xaf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0x20, 
  0x00, 0x00, 0x00, 0x5d, 0x1e, 0x70, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xaf, 0x5d, 0x1d, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x1c, 0x10, 0x5d, 0x1e, 0x9f, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x70, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x80, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0x8f, 0x5d, 0x1d, 0x40, 0x55, 0x1c, 0x10, 0x00, 0x00, 0x00, 0x55, 0x1c, 0x10, 0x5d, 0x1d, 0x40, 0x5d, 0x1e, 0x7f, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1d, 0x40, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xdf, 0x5d, 0x1d, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5d, 0x1e, 0x50, 0x5d, 0x1e, 0xa0, 0x5d, 0x1e, 0xcf, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xff, 0x5d, 0x1e, 0xef, 0x5d, 0x1e, 0xdf, 0x5d, 0x1e, 0x9f, 0x5d, 0x1d, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x9f, 0x54, 0x40, 0xef, 0xa0, 0x57, 0xbf, 0xec, 0x9f, 0x56, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef, 0xa1, 0x56, 0x7f, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xef, 0xa1, 0x56, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdf, 0x9f, 0x50, 0x10, 0xee, 0xa0, 0x57, 0xaf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x56, 0xcf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xaf, 0xef, 0x9f, 0x50, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x9f, 0x58, 0x20, 0xee, 0xa0, 0x56, 0xcf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x57, 0x70, 0x00, 0x00, 0x00, 0x00, 0xed, 0x9f, 0x58, 0x80, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xdf, 0xe7, 0x9f, 0x58, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x9f, 0x58, 0x20, 0xee, 0xa0, 0x57, 0xdf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xef, 0xec, 0x9f, 0x56, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xec, 0x9f, 0x56, 0x50, 0xee, 0xa0, 0x57, 0xef, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xdf, 0xe7, 0x9f, 0x58, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x9f, 0x58, 0x20, 0xee, 0xa0, 0x57, 0xdf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xef, 0xef, 0x9f, 0x5a, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xea, 0x9f, 0x5a, 0x30, 0xee, 0xa0, 0x57, 0xef, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xdf, 0xef, 0x9f, 0x50, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef, 0xa0, 0x57, 0xbf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xef, 0xef, 0x9f, 0x5a, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xea, 0x9f, 0x5a, 0x30, 0xee, 0xa0, 0x57, 0xef, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xef, 0xa1, 0x56, 0x7f, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xec, 0x9f, 0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xec, 0x9f, 0x58, 0x60, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x57, 0x70, 0x00, 0x00, 0x00, 0x00, 
  0xe7, 0x9f, 0x58, 0x20, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x57, 0x90, 0x00, 0x00, 0x00, 0x00, 0xef, 0xa0, 0x57, 0xbf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xaf, 0xef, 0x9f, 0x50, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x9f, 0x58, 0x20, 0xef, 0xa0, 0x57, 0xbf, 0xe7, 0x9f, 0x58, 0x20, 0x00, 0x00, 0x00, 0x00, 0xed, 0x9f, 0x57, 0x90, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xef, 0xef, 0x9f, 0x50, 0x10, 
  0xed, 0xa0, 0x57, 0x9f, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xdf, 0xef, 0x9f, 0x58, 0x20, 0xea, 0x9f, 0x55, 0x30, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xeb, 0x9f, 0x58, 0x40, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x9f, 0x54, 0x40, 0xee, 0xa0, 0x57, 0xef, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xcf, 0x00, 0x00, 0x00, 0x00, 0xef, 0x9f, 0x50, 0x10, 0xee, 0xa0, 0x57, 0xef, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x56, 0x80, 
  0xee, 0xa0, 0x56, 0xcf, 0xee, 0xa0, 0x57, 0xff, 0xef, 0xa0, 0x57, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef, 0xa0, 0x56, 0xaf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xbf, 0xef, 0x9f, 0x50, 0x10, 0xef, 0xa1, 0x57, 0x6f, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xdf, 0xef, 0x9f, 0x58, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xed, 0x9f, 0x57, 0x90, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xdf, 
  0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xec, 0x9f, 0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef, 0xa0, 0x57, 0x8f, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xef, 0xa0, 0x57, 0xaf, 0xef, 0x9f, 0x50, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xec, 0x9f, 0x58, 0x60, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 
  0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xec, 0x9f, 0x55, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdf, 0x9f, 0x50, 0x10, 0xee, 0xa0, 0x57, 0xaf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x57, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xed, 0x9f, 0x57, 0x70, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 
  0xee, 0xa0, 0x56, 0xcf, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x55, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x9f, 0x58, 0x20, 0xee, 0xa0, 0x57, 0xdf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x57, 0x70, 0xdf, 0x9f, 0x50, 0x10, 0xef, 0xa0, 0x57, 0xbf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xaf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xed, 0xa0, 0x57, 0x9f, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xcf, 
  0xed, 0x9f, 0x56, 0x80, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xef, 0xef, 0x9f, 0x50, 0x10, 0x00, 0x00, 0x00, 0x00, 0xee, 0xa0, 0x56, 0xcf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xef, 0xeb, 0x9f, 0x58, 0x40, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x9f, 0x54, 0x40, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xef, 0x9f, 0x55, 0x30, 0xe7, 0x9f, 0x58, 0x20, 0xee, 0xa0, 0x57, 0xdf, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x55, 0x90, 
  0xef, 0x9f, 0x50, 0x10, 0xee, 0xa0, 0x57, 0xef, 0xee, 0xa0, 0x57, 0xff, 0xed, 0xa0, 0x57, 0x9f, 0x00, 0x00, 0x00, 0x00, 0xef, 0x9f, 0x58, 0x20, 0xee, 0xa0, 0x57, 0xbf, 0xef, 0x9f, 0x58, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xef, 0x9f, 0x50, 0x10, 0xef, 0xa0, 0x56, 0xaf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xbf, 0x00, 0x00, 0x00, 0x00, 0xee, 0xa0, 0x57, 0xaf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xef, 0xef, 0x9f, 0x58, 0x20, 
  0x00, 0x00, 0x00, 0x00, 0xed, 0x9f, 0x57, 0x70, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xaf, 0xe7, 0x9f, 0x58, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdf, 0x9f, 0x50, 0x10, 0xef, 0xa0, 0x57, 0x9f, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x57, 0x70, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xed, 0x9f, 0x58, 0x80, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xdf, 0xed, 0xa0, 0x56, 0x8f, 0xeb, 0x9f, 0x54, 0x40, 0xdf, 0x9f, 0x50, 0x10, 0x00, 0x00, 0x00, 0x00, 0xdf, 0x9f, 0x50, 0x10, 0xeb, 0x9f, 0x54, 0x40, 0xef, 0xa1, 0x56, 0x7f, 0xee, 0xa0, 0x57, 0xef, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xed, 0x9f, 0x58, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xeb, 0x9f, 0x58, 0x40, 0xee, 0xa0, 0x57, 0xdf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xdf, 0xeb, 0x9f, 0x58, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xec, 0x9f, 0x56, 0x50, 0xed, 0x9f, 0x56, 0xa0, 0xee, 0xa0, 0x56, 0xcf, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xff, 0xee, 0xa0, 0x57, 0xef, 0xee, 0xa0, 0x57, 0xdf, 0xed, 0xa0, 0x57, 0x9f, 0xeb, 0x9f, 0x58, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t hum = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 19,
  .header.h = 20,
  .data_size = 380 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = hum_map,
};
