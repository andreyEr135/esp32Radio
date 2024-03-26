#include "uiApPage.h"

#include "uiApTitle.h"
#include "uiApName.h"
#include "uiApPswd.h"
#include "uiApIp.h"


//#include "uiModules.h"

void showApPage()
{
  mainWin = true;

  showApTitleLabel();

  showApNameLabel();

  showApPswdLabel();

  showApIpLabel();

}