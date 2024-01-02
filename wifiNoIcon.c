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

#ifndef LV_ATTRIBUTE_IMG_WIFINOICON
#define LV_ATTRIBUTE_IMG_WIFINOICON
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_WIFINOICON uint8_t wifiNoIcon_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x40, 0xb7, 0x9f, 0xb7, 0xdf, 0xb7, 0xef, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xcf, 0xb7, 0x9f, 0xb6, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x50, 0xb7, 0xdf, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xdf, 0xb6, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xb6, 0x10, 0xb7, 0x9f, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xdf, 0xb7, 0xdf, 0xb7, 0xdf, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0x9f, 0xb6, 0x10, 0x00, 0x00, 
  0xb6, 0x20, 0xb7, 0xcf, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xbf, 0xb6, 0x40, 0xb6, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x10, 0xb6, 0x50, 0xb7, 0xa0, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xdf, 0xb6, 0x20, 
  0xb7, 0xbf, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xdf, 0xb6, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x30, 0xb7, 0xdf, 0xb7, 0xff, 0xb7, 0xff, 0xb6, 0xc0, 
  0xb6, 0x60, 0xb7, 0xff, 0xb7, 0xcf, 0xb6, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x10, 0xb6, 0x50, 0xb6, 0x60, 0xb6, 0x40, 0xb6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x20, 0xb7, 0xcf, 0xb7, 0xff, 0xb6, 0x70, 
  0x00, 0x00, 0xb6, 0x70, 0xb6, 0x10, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x40, 0xb7, 0xbf, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xbf, 0xb6, 0x20, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x10, 0xb6, 0x60, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb7, 0x7f, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x70, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xdf, 0xb7, 0x90, 0xb6, 0x80, 0xb7, 0x90, 0xb7, 0xdf, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb6, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x10, 0xb7, 0xdf, 0xb7, 0xef, 0xb6, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x60, 0xb7, 0xef, 0xb7, 0xdf, 0xb6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x20, 0xb6, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x30, 0xb6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb7, 0x6f, 0xb7, 0xaf, 0xb6, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x40, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb6, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x80, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb6, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x50, 0xb7, 0xff, 0xb7, 0xff, 0xb7, 0xff, 0xb6, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x90, 0xb7, 0xff, 0xb7, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x40, 0x34, 0xa5, 0x9f, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0xef, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xcf, 0x34, 0xa5, 0x9f, 0x14, 0xa5, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x50, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x14, 0xa5, 0x10, 0x34, 0xa5, 0x9f, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x34, 0xa5, 0x9f, 0x14, 0xa5, 0x10, 0x00, 0x00, 0x00, 
  0x14, 0xa5, 0x20, 0x14, 0xa5, 0xcf, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xbf, 0x14, 0xa5, 0x40, 0x14, 0xa5, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x10, 0x14, 0xa5, 0x50, 0x14, 0xa5, 0xa0, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0x20, 
  0x34, 0xa5, 0xbf, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x30, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xc0, 
  0x14, 0xa5, 0x60, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xcf, 0x14, 0xa5, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x10, 0x14, 0xa5, 0x50, 0x14, 0xa5, 0x60, 0x14, 0xa5, 0x40, 0x14, 0xa5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x20, 0x14, 0xa5, 0xcf, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0x70, 
  0x00, 0x00, 0x00, 0x14, 0xa5, 0x70, 0x14, 0xa5, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x40, 0x34, 0xa5, 0xbf, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x34, 0xa5, 0xbf, 0x14, 0xa5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x10, 0x14, 0xa5, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x7f, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x34, 0xa5, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x70, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0x90, 0x14, 0xa5, 0x80, 0x14, 0xa5, 0x90, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x10, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0xef, 0x14, 0xa5, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x60, 0x14, 0xa5, 0xef, 0x14, 0xa5, 0xdf, 0x14, 0xa5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x20, 0x14, 0xa5, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x30, 0x14, 0xa5, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x6f, 0x34, 0xa5, 0xaf, 0x14, 0xa5, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x40, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x80, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x50, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xa5, 0x90, 0x14, 0xa5, 0xff, 0x14, 0xa5, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x40, 0xa5, 0x34, 0x9f, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0xef, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xcf, 0xa5, 0x34, 0x9f, 0xa5, 0x14, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x50, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xa5, 0x14, 0x10, 0xa5, 0x34, 0x9f, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x34, 0x9f, 0xa5, 0x14, 0x10, 0x00, 0x00, 0x00, 
  0xa5, 0x14, 0x20, 0xa5, 0x14, 0xcf, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xbf, 0xa5, 0x14, 0x40, 0xa5, 0x14, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x10, 0xa5, 0x14, 0x50, 0xa5, 0x14, 0xa0, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0x20, 
  0xa5, 0x34, 0xbf, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x30, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xc0, 
  0xa5, 0x14, 0x60, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xcf, 0xa5, 0x14, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x10, 0xa5, 0x14, 0x50, 0xa5, 0x14, 0x60, 0xa5, 0x14, 0x40, 0xa5, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x20, 0xa5, 0x14, 0xcf, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0x70, 
  0x00, 0x00, 0x00, 0xa5, 0x14, 0x70, 0xa5, 0x14, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x40, 0xa5, 0x34, 0xbf, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x34, 0xbf, 0xa5, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x10, 0xa5, 0x14, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x7f, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x34, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x70, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0x90, 0xa5, 0x14, 0x80, 0xa5, 0x14, 0x90, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x10, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0xef, 0xa5, 0x14, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x60, 0xa5, 0x14, 0xef, 0xa5, 0x14, 0xdf, 0xa5, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x20, 0xa5, 0x14, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x30, 0xa5, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x6f, 0xa5, 0x34, 0xaf, 0xa5, 0x14, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x40, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x80, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x50, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa5, 0x14, 0x90, 0xa5, 0x14, 0xff, 0xa5, 0x14, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x40, 0xa2, 0xa2, 0xa2, 0x9f, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0xef, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xcf, 0xa2, 0xa2, 0xa2, 0x9f, 0x9f, 0x9f, 0x9f, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x50, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xdf, 0x9f, 0x9f, 0x9f, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x10, 0xa2, 0xa2, 0xa2, 0x9f, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa2, 0xa2, 0xa2, 0x9f, 0x9f, 0x9f, 0x9f, 0x10, 0x00, 0x00, 0x00, 0x00, 
  0x9f, 0x9f, 0x9f, 0x20, 0xa1, 0xa1, 0xa1, 0xcf, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa0, 0xa0, 0xa0, 0xbf, 0x9f, 0x9f, 0x9f, 0x40, 0x9f, 0x9f, 0x9f, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x10, 0x9f, 0x9f, 0x9f, 0x50, 0xa1, 0xa1, 0xa1, 0xa0, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xdf, 0x9f, 0x9f, 0x9f, 0x20, 
  0xa2, 0xa2, 0xa2, 0xbf, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xdf, 0x9f, 0x9f, 0x9f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x30, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0x9f, 0x9f, 0x9f, 0xc0, 
  0x9f, 0x9f, 0x9f, 0x60, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xcf, 0x9f, 0x9f, 0x9f, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x10, 0x9f, 0x9f, 0x9f, 0x50, 0x9f, 0x9f, 0x9f, 0x60, 0x9f, 0x9f, 0x9f, 0x40, 0x9f, 0x9f, 0x9f, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x20, 0xa1, 0xa1, 0xa1, 0xcf, 0xa1, 0xa1, 0xa1, 0xff, 0x9f, 0x9f, 0x9f, 0x70, 
  0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x70, 0x9f, 0x9f, 0x9f, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x40, 0xa2, 0xa2, 0xa2, 0xbf, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa2, 0xa2, 0xa2, 0xbf, 0x9f, 0x9f, 0x9f, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x10, 0x9f, 0x9f, 0x9f, 0x60, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa1, 0xa1, 0xa1, 0x7f, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa3, 0xa3, 0xa3, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x70, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0x90, 0x9f, 0x9f, 0x9f, 0x80, 0xa1, 0xa1, 0xa1, 0x90, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0x9f, 0x9f, 0x9f, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x10, 0xa1, 0xa1, 0xa1, 0xdf, 0xa1, 0xa1, 0xa1, 0xef, 0x9f, 0x9f, 0x9f, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x60, 0xa1, 0xa1, 0xa1, 0xef, 0xa1, 0xa1, 0xa1, 0xdf, 0x9f, 0x9f, 0x9f, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x20, 0x9f, 0x9f, 0x9f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x30, 0x9f, 0x9f, 0x9f, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa1, 0xa1, 0xa1, 0x6f, 0xa2, 0xa2, 0xa2, 0xaf, 0x9f, 0x9f, 0x9f, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x40, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0x9f, 0x9f, 0x9f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x80, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0x9f, 0x9f, 0x9f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x50, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xff, 0x9f, 0x9f, 0x9f, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x9f, 0x9f, 0x90, 0xa1, 0xa1, 0xa1, 0xff, 0xa1, 0xa1, 0xa1, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t wifiNoIcon = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 19,
  .header.h = 16,
  .data_size = 304 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = wifiNoIcon_map,
};
