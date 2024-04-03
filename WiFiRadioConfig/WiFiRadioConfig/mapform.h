#ifndef MAPFORM_H
#define MAPFORM_H

#include <QWidget>

namespace Ui {
class MapForm;
}

class MapForm : public QWidget
{
    Q_OBJECT

public:
    explicit MapForm(QWidget *parent = nullptr, double _lat = 0, double _lon = 0);
    ~MapForm();

signals:
    void updatePos(double _lat, double _lon);

private slots:
    void onDoubleClick(QPointF pos);
private:
    Ui::MapForm *ui;
    double lat;
    double lon;
};

#endif // MAPFORM_H
