#ifndef WIFIRADIOCONFIG_H
#define WIFIRADIOCONFIG_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QHttpMultiPart>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QFileDialog>
#include <QMessageBox>

#include "mapform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WiFiRadioConfig; }
QT_END_NAMESPACE

class WiFiRadioConfig : public QMainWindow
{
    Q_OBJECT

public:
    WiFiRadioConfig(QWidget *parent = nullptr);
    ~WiFiRadioConfig();

private slots:
    void on_addStation_clicked();
    void onUpClicked(int id);
    void onDownClicked(int id);
    void onRemoveClicked(int id);

    void on_connect_clicked();

    void on_openFile_clicked();

    void on_saveConfig_clicked();

    void on_loadConfig_clicked();

    void on_openMap_clicked();
    void onUpdatePos(double _lat, double _lon);

private:
    Ui::WiFiRadioConfig *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    bool ReadJson(QString _json);
    bool SaveJson(QString fileName);
    void clearListStations();
    void addStation(int id, QString name, QString path, QString meta_path);
    MapForm *mapF;
};
#endif // WIFIRADIOCONFIG_H
