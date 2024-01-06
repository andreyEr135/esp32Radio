#include "uiWeatherPage.h"


//#include "uiModules.h"
#include "uiCurrentStationIcon.h"
#include "uiStationName.h"
#include "uiTitleLabel.h"
#include "uiTimeInfo.h"
#include "uiPlayPauseBtn.h"
#include "uiVersionLabel.h"
#include "uiPrevBtn.h"
#include "uiNextBtn.h"
#include "uiMenuBtn.h"
#include "uiRadioStationInfo.h"

#include "uiCityName.h"
#include "uiOblName.h"
#include "uiConditionIcon.h"
#include "uiTempLabel.h"
#include "uiPressureLabel.h"
#include "uiHumInfo.h"

void showWeatherPage()
{
  mainWin = false;
  hideVersionStr();
  hideRadioStationInfo();
  hideCurrentRadioStationIcon();

  hidePrevBtn();
  hidePlayPauseBtn();
  hideNextBtn();


  reshowTimeInfo();
  reShowNameStationLabel();
  reShowTitleInfoLabel();

  showNameCityLabel();

  showNameOblLabel();

  conditionIconDraw();

  reShowTempLabel();

  showPressureLabel();

  showHumInfo();
}

void reShowWeatherPage()
{
  writeCityName();
  writeOblName();
  writePressure();
  reShowHumInfo();
}