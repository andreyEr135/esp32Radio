#include "uiMainPage.h"

//#include "uiModules.h"
#include "uiVolumeInfo.h"
#include "uiVolumePage.h"
#include "uiMenuPage.h"
#include "uiCurrentStationIcon.h"
#include "uiStationName.h"
#include "uiTitleLabel.h"
#include "uiWifiInfo.h"
#include "uiBatteryIcon.h"
#include "uiTimeInfo.h"
#include "uiPlayPauseBtn.h"
#include "uiPlayPauseIcon.h"
#include "uiVersionLabel.h"
#include "uiPrevBtn.h"
#include "uiNextBtn.h"
#include "uiMenuBtn.h"
#include "uiVolOffBtn.h"
#include "uiRadioStationInfo.h"

#include "uiCityName.h"
#include "uiOblName.h"
#include "uiConditionIcon.h"
#include "uiTempLabel.h"
#include "uiPressureLabel.h"
#include "uiHumInfo.h"

void createMenu()
{
  showVolumeBtnInfo();
  showMenuBtn();
  showVolumeOffBtn();
}

void showMainPage()
{
  mainWin = true;
  showTimeStr();

  showVersionStr();

  showTempLabel();  

  wifiInfoDraw();

  batteryStatusDraw();

  showNameStationLabel();

  showRadioStationInfo();

  showCurrentRadioStationIcon();

  showTitleInfoLabel();

  showPlayPauseIcon();

  showPrevBtn();

  showPlayPauseBtn();

  showNextBtn();

  createMenu();

  volDisplay = false;
  listDisplay = false;

}

void showMainPageAfterWeather()
{
  mainWin = true;
  hideNameCityLabel();
  hideNameOblLabel();
  conditionIconHide();
  hidePressureLabel();
  hideHumInfo();

  reshowTimeInfo();
  showVersionStr();
  reShowTempLabel();

  reShowNameStationLabel();
  showRadioStationInfo();
  showCurrentRadioStationIcon();
  reShowTitleInfoLabel();

  showPrevBtn();
  showPlayPauseBtn();
  showNextBtn();

}