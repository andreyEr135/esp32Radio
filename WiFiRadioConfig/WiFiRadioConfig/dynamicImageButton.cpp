#include "dynamicImageButton.h"

dynamicImageButton::dynamicImageButton(QWidget *parent) :
    QLabel(parent)
{
    name = "";
}

dynamicImageButton::~dynamicImageButton()
{

}

bool dynamicImageButton :: event(QEvent *myEvent)
{
    switch(myEvent->type())
    {
        case(QEvent :: MouseButtonPress):   // Identify Mouse press Event
        {
            emit dButtonPressed();
            return true;
            break;
        }

        case(QEvent :: MouseButtonRelease):   // Identify Mouse press Event
        {
            emit dButtonClicked();
            return true;
            break;
        }
    }
    return QWidget::event(myEvent);
}
