#include "uiApPage.h"

#include "uiApTitle.h"
#include "uiApName.h"
#include "uiApPswd.h"
#include "uiApIp.h"


//#include "uiModules.h"

void showApPage(bool err)
{
  mainWin = true;

  showApTitleLabel(err);

  showApNameLabel(err);

  if (!err)
  {
    showApPswdLabel();
    showApIpLabel();
  }

}