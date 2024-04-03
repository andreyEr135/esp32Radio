#include "radioinfo.h"

radioInfo::radioInfo(QWidget *parent, int _id) :
    QFrame(parent)
{
    id = _id;
    setFrameShape(QFrame::Panel);
    setLineWidth(2);
    setFixedSize(1030,191);
    numStation = new QLabel(this);
    numStation->setGeometry(10,10, 41,21);
    numStation->setText(QString::number(id));

    QLabel *titleNameStation = new QLabel(this);
    //titleNameStation->setStyleSheet("");
    titleNameStation->setGeometry(40,20,103,31);
    titleNameStation->setText("Название");

    nameStation = new QLineEdit(this);
    nameStation->setGeometry(160,10,760,50);

    QLabel *titleAddressStation = new QLabel(this);
    titleAddressStation->setGeometry(40,78,141,31);
    titleAddressStation->setText("Адрес потока");

    addressStation = new QLineEdit(this);
    addressStation->setGeometry(190,70,730,50);

    QLabel *titleAddressMetaStation = new QLabel(this);
    titleAddressMetaStation->setGeometry(40,138,201,31);
    titleAddressMetaStation->setText("Адрес метаданных");

    addressMetaStation = new QLineEdit(this);
    addressMetaStation->setGeometry(250,130,670,50);

    upBtn = new dynamicImageButton(this);
    upBtn->setGeometry(950, 10, 50, 50);
    QPixmap pUp(":/images/up.svg");
    upBtn->setPixmap(pUp);
    upBtn->SetName(QString("up_%1").arg(id));
//    if (id == 1) upBtn->setEnabled(false);
//    else upBtn->setEnabled(true);
    connect(upBtn, SIGNAL(dButtonClicked()), this, SLOT(onButtonsClicked()));

    delBtn = new dynamicImageButton(this);
    delBtn->setGeometry(950, 70, 50, 50);
    QPixmap pDel(":/images/remove.svg");
    delBtn->setPixmap(pDel);
    delBtn->SetName(QString("remove_%1").arg(id));
    connect(delBtn, SIGNAL(dButtonClicked()), this, SLOT(onButtonsClicked()));

    downBtn = new dynamicImageButton(this);
    downBtn->setGeometry(950, 130, 50, 50);
    QPixmap pDown(":/images/down.svg");
    downBtn->setPixmap(pDown);
    downBtn->SetName(QString("down_%1").arg(id));
    connect(downBtn, SIGNAL(dButtonClicked()), this, SLOT(onButtonsClicked()));

}

void radioInfo::onButtonsClicked()
{
    dynamicButton *button = (dynamicButton*) sender();
    QString name = button->GetName();
    if (name.contains("up"))
    {
        emit up_signal(id);

    } else if (name.contains("down"))
    {
        emit down_signal(id);

    } else if (name.contains("remove"))
    {
        emit remove_signal(id);
    }
}

void radioInfo::SetId(int _id)
{
    id = _id;
    numStation->setText(QString::number(id));
    upBtn->SetName(QString("up_%1").arg(id));
    delBtn->SetName(QString("remove_%1").arg(id));
    downBtn->SetName(QString("down_%1").arg(id));
}

