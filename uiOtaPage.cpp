#include "uiOtaPage.h"

#include "uiOtaTitle.h"
#include "uiApName.h"
#include "uiApPswd.h"
#include "uiApIp.h"


//#include "uiModules.h"

void showOtaPage()
{
  mainWin = true;

  showOtaTitleLabel();

  showApNameLabel();

  showApPswdLabel();

  showApIpLabel();

}