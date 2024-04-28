#include "wifisearch.h"
#include "ui_wifisearch.h"
#include <QDebug>
WiFiSearch::WiFiSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WiFiSearch)
{
    ui->setupUi(this);
    listModel = new QStandardItemModel(0,1);


    //ui->WiFiList->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->WiFiList->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->WiFiList->setModel(listModel);
    ui->WiFiList->setVerticalScrollBar(new QScrollBar(ui->WiFiList));
    ui->WiFiList->setColumnWidth(0,470);
    ui->WiFiList->verticalHeader()->hide();
    ui->WiFiList->horizontalHeader()->hide();
    ui->WiFiList->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

WiFiSearch::~WiFiSearch()
{
    delete ui;
}

void WiFiSearch::closeEvent(QCloseEvent *bar)
{
    // Do something
    emit closeForm();
}

void WiFiSearch::scanWiFi()
{
    //findTimer = new QTimer();
    //findTimer->setInterval(1000);
    //connect(findTimer,&QTimer::timeout,this,&WiFiSearch::findActiveWirelesses);
    //findTimer->start();
    foundCount = 0;

    //ui->treeWidgetWiFis->setColumnWidth(1,200);
    findActiveWirelesses();
}

void WiFiSearch::findActiveWirelesses()
{
    QNetworkConfigurationManager ncm;
    netcfgList = ncm.allConfigurations();
    WiFisList.clear();
    //listModel->clear();
    //ui->WiFiList->setModel(listModel);
    //ui->WiFiList->setColumnWidth(0,470);

    listModel->removeRows(0, listModel->rowCount());

    for (auto &x : netcfgList)
    {
        if (x.bearerType() == QNetworkConfiguration::BearerWLAN)
        {
            if(x.name() == "")
                WiFisList << "Unknown(Other Network)";
            else
                WiFisList << x.name();
        }
    }
    for(int i=0; i<WiFisList.size(); i++)
    {
        QStandardItem *item = new QStandardItem(QString(WiFisList[i]));
        listModel->appendRow(item);
        //ui->WiFiList
    }
}

void WiFiSearch::on_searchWiFi_clicked()
{
    scanWiFi();

}


void WiFiSearch::on_WiFiList_clicked(const QModelIndex &index)
{
    checkedWiFi = (index.model()->data(index.model()->index(index.row(),index.column())).toString());
}


void WiFiSearch::on_WiFiList_doubleClicked(const QModelIndex &index)
{
    checkedWiFi = (index.model()->data(index.model()->index(index.row(),index.column())).toString());
    emit networkCLicked(checkedWiFi);
    //this->close();
}


void WiFiSearch::on_OkBtn_clicked()
{
    if (checkedWiFi == "")
    {
        QErrorMessage msg(this);
        msg.showMessage(QString("Ошибка! Сеть не выбрана!"));
        msg.exec();
        return;
    }
    emit networkCLicked(checkedWiFi);

}


void WiFiSearch::on_CloseBtn_clicked()
{
    this->close();
}

