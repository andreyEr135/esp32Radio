#ifndef DYNAMICIMAGEBUTTON_H
#define DYNAMICIMAGEBUTTON_H

//#include <QObject>

#include <QLabel>
#include <QEvent>

class dynamicImageButton : public QLabel
{
    Q_OBJECT
public:

    explicit dynamicImageButton(QWidget *parent = 0);
    ~dynamicImageButton();
    void SetName(QString _name)
    {
        name = _name;
    };

    QString GetName()
    {
        return name;
    };

signals:
    void dButtonClicked();       // Signal to emit

protected:
    bool event(QEvent *myEvent);

private:
    QString name;
};

#endif // DYNAMICIMAGEBUTTON_H
