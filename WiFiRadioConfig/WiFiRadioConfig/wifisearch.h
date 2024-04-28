#ifndef WIFISEARCH_H
#define WIFISEARCH_H

#include <QWidget>
#include <QTimer>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QStandardItemModel>
#include <QScrollBar>
#include <QErrorMessage>

namespace Ui {
class WiFiSearch;
}

class WiFiSearch : public QWidget
{
    Q_OBJECT

public:
    explicit WiFiSearch(QWidget *parent = nullptr);
    ~WiFiSearch();

signals:
    void closeForm();
    void networkCLicked(QString ssid);

public slots:
    void findActiveWirelesses();

    void on_searchWiFi_clicked();

    void on_WiFiList_clicked(const QModelIndex &index);

    void on_WiFiList_doubleClicked(const QModelIndex &index);

private slots:
    void on_OkBtn_clicked();

    void on_CloseBtn_clicked();

private:
    Ui::WiFiSearch *ui;
    void closeEvent(QCloseEvent *bar);
    void scanWiFi();
    int foundCount;
    QNetworkConfiguration netcfg;
    QStringList WiFisList;
    QList<QNetworkConfiguration> netcfgList;
    QTimer *findTimer;
    QStandardItemModel* listModel;
    QNetworkSession *session;
    QString checkedWiFi;
};




#endif // WIFISEARCH_H
