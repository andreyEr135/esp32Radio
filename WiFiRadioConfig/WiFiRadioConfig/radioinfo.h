#ifndef RADIOINFO_H
#define RADIOINFO_H

#include <QFrame>
#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <dynamicbutton.h>
#include <dynamicImageButton.h>

class radioInfo : public QFrame
{
    Q_OBJECT
public:
    radioInfo(QWidget *parent = 0, int _id = 0);
    QLabel *numStation;
    QLineEdit *nameStation;
    QLineEdit *addressStation;
    QLineEdit *addressMetaStation;

    dynamicImageButton *upBtn;
    dynamicImageButton *downBtn;
    //dynamicButton *delBtn;
    dynamicImageButton *delBtn;

    int GetId()
    {
        return id;
    };
    void SetId(int _id);

signals:
    void up_signal(int _id);
    void down_signal(int _id);
    void remove_signal(int _id);

private slots:
    void onButtonsClicked();


private:
    int id;
};

#endif // RADIOINFO_H
