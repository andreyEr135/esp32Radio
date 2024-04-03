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
        case(QEvent :: MouseButtonRelease):   // Identify Mouse press Event
        {
            emit dButtonClicked();
            return true;
            break;
        }
    }
    return QWidget::event(myEvent);
}
