#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

//#include <QObject>

#include <QPushButton>

class dynamicButton : public QPushButton
{
    Q_OBJECT
public:

    explicit dynamicButton(QWidget *parent = 0);
    ~dynamicButton();
    void SetName(QString _name)
    {
        name = _name;
    };

    QString GetName()
    {
        return name;
    };

private:
    QString name;
};

#endif // DYNAMICBUTTON_H
