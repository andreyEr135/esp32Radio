#include "wifiradioconfig.h"
#include "ui_wifiradioconfig.h"

#include "qerrormessage.h"
#include "dynamicImageButton.h"

#include "radioinfo.h"
#include "qdebug.h"


QVBoxLayout *vList;
int countStations;

bool getFile;

WiFiRadioConfig::WiFiRadioConfig(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WiFiRadioConfig)
{
    ui->setupUi(this);
    //QGridLayout *grL = new QGridLayout();

    dynamicImageButton *openFile = new dynamicImageButton(this);
    openFile->setFixedSize(49,35);
    QPixmap pOpen(":/images/open.svg");
    openFile->setPixmap(pOpen);
    openFile->SetName("open");
    connect(openFile, SIGNAL(dButtonClicked()), this, SLOT(onButtonsClicked()));
    ui->horizontalLayout_7->addWidget(openFile);


    dynamicImageButton *findWiFi = new dynamicImageButton(this);
    findWiFi->setFixedSize(20,30);
    QPixmap pFind(":/images/findWiFi.svg");
    findWiFi->setPixmap(pFind);
    findWiFi->SetName("findWiFi");
    connect(findWiFi, SIGNAL(dButtonClicked()), this, SLOT(onButtonsClicked()));
    ui->horizontalLayout_2->addWidget(findWiFi);


    dynamicImageButton *showPswd = new dynamicImageButton(this);
    showPswd->setFixedSize(20,30);
    QPixmap pShow(":/images/showPasswd.svg");
    showPswd->setPixmap(pShow);
    showPswd->SetName("showPasswd");



    connect(showPswd, SIGNAL(dButtonPressed()), this, SLOT(onButtonPressed()));
    connect(showPswd, SIGNAL(dButtonClicked()), this, SLOT(onButtonsClicked()));
    ui->horizontalLayout_3->addWidget(showPswd);

    QWidget *wList = new QWidget(ui->radioList);
    vList = new QVBoxLayout(wList);
    spacer = new QSpacerItem(0, 5,
             QSizePolicy::Ignored, QSizePolicy::MinimumExpanding);
    vList->addSpacerItem(spacer);
    //vList->setDirection(QBoxLayout::TopToBottom);

    ui->radioList->setWidget(wList);
    ui->loadConfig->setEnabled(false);

    ui->passwdWiFi->setEchoMode(QLineEdit::Password);
    //ui->passwdWiFi->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    countStations = 0;

    ui->ipAddress->setAlignment(Qt::AlignVCenter);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTout()));

    QPixmap pStat(":/images/statusDisconnect.svg");
    ui->status->setPixmap(pStat);

    manager = new QNetworkAccessManager(this);
    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                QErrorMessage msg(this);
                msg.showMessage(QString("Ошибка! %1").arg(reply->errorString()));
                msg.exec();
                return;
            }

            if (getFile)
            {
                QString answer = reply->readAll();
                ReadJson(answer);
                ui->connect->setText("Подключено");
                QPixmap pStat(":/images/statusConnect.svg");
                ui->status->setPixmap(pStat);
                ui->loadConfig->setEnabled(true);
                timer->start(10000);
            } else
            {
                //qDebug() << reply->readAll();
                if (reply->readAll().contains("ERROR"))
                {
                    QErrorMessage msg(this);
                    msg.showMessage("Ошибка! Загрузка не произошла");
                    msg.exec();
                } else
                {
                    QString message_d = QString("Загрузка успешна");
                    QMessageBox::information(this, "Загрузка успешна", message_d);
                }
            }
        }
    );


}

WiFiRadioConfig::~WiFiRadioConfig()
{
    delete ui;
}

void WiFiRadioConfig::onUpClicked(int id)
{
    if (id == 1) return;
    for(int i = 0; i < vList->count(); i++){
        radioInfo *info = qobject_cast<radioInfo*>(vList->itemAt(i)->widget());
        if (info->GetId() == id)
        {
            radioInfo *info_pred = qobject_cast<radioInfo*>(vList->itemAt(i-1)->widget());

            QString name = info->nameStation->text();
            QString addr = info->addressStation->text();
            QString addr_meta = info->addressMetaStation->text();

            info->nameStation->setText(info_pred->nameStation->text());
            info->addressStation->setText(info_pred->addressStation->text());
            info->addressMetaStation->setText(info_pred->addressMetaStation->text());

            info_pred->nameStation->setText(name);
            info_pred->addressStation->setText(addr);
            info_pred->addressMetaStation->setText(addr_meta);
        }
    }
}
void WiFiRadioConfig::onDownClicked(int id)
{
    if (id == countStations) return;
    for(int i = 0; i < vList->count(); i++){
        radioInfo *info = qobject_cast<radioInfo*>(vList->itemAt(i)->widget());
        if (info->GetId() == id)
        {
            radioInfo *info_next = qobject_cast<radioInfo*>(vList->itemAt(i+1)->widget());

            QString name = info->nameStation->text();
            QString addr = info->addressStation->text();
            QString addr_meta = info->addressMetaStation->text();

            info->nameStation->setText(info_next->nameStation->text());
            info->addressStation->setText(info_next->addressStation->text());
            info->addressMetaStation->setText(info_next->addressMetaStation->text());

            info_next->nameStation->setText(name);
            info_next->addressStation->setText(addr);
            info_next->addressMetaStation->setText(addr_meta);
        }
    }

}
void WiFiRadioConfig::onRemoveClicked(int id)
{
    vList->removeItem(spacer);
    for(int i = 0; i < vList->count(); i++){
        radioInfo *info = qobject_cast<radioInfo*>(vList->itemAt(i)->widget());
        if(info->GetId() == id){
            if (id < countStations) {
                for (int j = 0; j < vList->count(); j++ )
                {
                    radioInfo *r_info = qobject_cast<radioInfo*>(vList->itemAt(j)->widget());
                    if (r_info->GetId() > info->GetId())
                    {
                        r_info->SetId(r_info->GetId() - 1);
                    }
                }
            }
            info->hide();
            delete info;
            countStations--;
        }
    }
    vList->addSpacerItem(spacer);
}


void WiFiRadioConfig::on_addStation_clicked()
{
    if (countStations == 30) {
        QErrorMessage msg(this);
        msg.showMessage("Максимальное количество радиостанций: 30");
        msg.exec();
        return;

    }
    countStations++;

    radioInfo *radioSetup = new radioInfo(this, countStations);
    connect(radioSetup, SIGNAL(up_signal(int)), this, SLOT(onUpClicked(int)));
    connect(radioSetup, SIGNAL(down_signal(int)), this, SLOT(onDownClicked(int)));
    connect(radioSetup, SIGNAL(remove_signal(int)), this, SLOT(onRemoveClicked(int)));

    vList->removeItem(spacer);
    vList->addWidget(radioSetup);

    vList->addSpacerItem(spacer);

}


void WiFiRadioConfig::on_connect_clicked()
{
    if (ui->ipAddress->text() == "")
    {
        QErrorMessage msg(this);
        msg.showMessage("Не задан ip адрес устройства!");
        msg.exec();
        return;
    }
    getFile = true;
    QString _url = QString("http://%1/?download=download_config.json").arg(ui->ipAddress->text());
    request.setUrl(QUrl(_url));
    if (countStations != 0) clearListStations();
    manager->get(request);
}

void WiFiRadioConfig::clearListStations()
{
    vList->removeItem(spacer);
    while (vList->count() != 0)
    {
        radioInfo *info = qobject_cast<radioInfo*>(vList->itemAt(0)->widget());
        info->hide();
        delete info;
        countStations--;

    }
}

void WiFiRadioConfig::addStation(int id, QString name, QString path, QString meta_path)
{
    on_addStation_clicked();
    qDebug() << countStations;
    radioInfo *info = qobject_cast<radioInfo*>(vList->itemAt(countStations-1)->widget());
    info->nameStation->setText(name);
    info->addressStation->setText(path);
    info->addressMetaStation->setText(meta_path);
}


bool WiFiRadioConfig::ReadJson(QString _json)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(_json.toUtf8(), &error);
    qDebug() << "Error: " << error.errorString() << error.offset << error.error;

    if (doc.isObject())
    {
        QJsonObject json = doc.object();

        ui->ssidWiFi->setText(json["ssid"].toString());
        ui->passwdWiFi->setText(json["password"].toString());

        QJsonValue weather = json.value("weather");

        if (weather.isObject())
        {

           QJsonObject obj = weather.toObject();
           ui->weatherToken->setText(obj["token"].toString());
           ui->weatherLat->setText(obj["lat"].toString());
           ui->weatherLon->setText(obj["lon"].toString());
        }



        QJsonValue stations = json.value("stations");

        if (stations.isObject())
        {
           QJsonObject obj = stations.toObject();
           int count = obj["count"].toString().toInt();

           if (count == 30) {
               QErrorMessage msg(this);
               msg.showMessage("Максимальное количество радиостанций: 30");
               msg.exec();
               count = 30;
           }

           QString strNameStation;
           for (int i = 0; i<count; i++)
           {
               strNameStation = QString("station%1").arg(i);
               QJsonValue station = obj.value(strNameStation);
               if (stations.isObject())
               {
                   QJsonObject obj_station = station.toObject();
                   QString name = obj_station["name"].toString();
                   QString path = obj_station["path"].toString();
                   QString meta_path = obj_station["meta"].toString();
                   if ((name == "") && (path == "") && (meta_path == "")) continue;
                   addStation(i, name, path, meta_path);

               }
           }

        }
    }
    return true;
}

bool WiFiRadioConfig::SaveJson(QString fileName)
{
    QJsonObject allJson;
    allJson["ssid"] = ui->ssidWiFi->text();
    allJson["password"] = ui->passwdWiFi->text();


    QJsonObject weatherObj;
    weatherObj["token"] = ui->weatherToken->text();
    weatherObj["lat"] = ui->weatherLat->text();
    weatherObj["lon"] = ui->weatherLon->text();
    allJson.insert("weather", weatherObj);

    QJsonObject stations;
    stations["count"] = QString::number(countStations);


    for(int i = 0; i < vList->count(); i++){
        QJsonObject stationObj;
        QString numStation = QString("station%1").arg(i);
        radioInfo *info = qobject_cast<radioInfo*>(vList->itemAt(i)->widget());
        stationObj["name"] = info->nameStation->text();
        stationObj["path"] = info->addressStation->text();
        stationObj["meta"] = info->addressMetaStation->text();
        stations.insert(numStation, stationObj);
    }

    allJson.insert("stations", stations);

    QJsonDocument doc(allJson);

    QFile jsonFile(fileName);
    if (!jsonFile.open(QIODevice::WriteOnly))
    {
        return false;
    }

    // Записываем текущий объект Json в файл
    jsonFile.write(doc.toJson(QJsonDocument::Indented));
    jsonFile.close();   // Закрываем файл
    return true;


}


void WiFiRadioConfig::on_openFile_clicked()
{
    QString str = ui->configFile->text();

    if (!str.isEmpty())
    {
        QFile file;
        file.setFileName(str);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString val = file.readAll();
        file.close();
        if (countStations != 0) clearListStations();
        ReadJson(val);
    }
}


void WiFiRadioConfig::on_saveConfig_clicked()
{
    QString strFilter="*.json";

    QString str = QFileDialog::getSaveFileName(0,
                                    "Сохранить конфигурацию",
                                    "",
                                    "*.json",
                                    &strFilter
                                    );

    if (!str.isEmpty())
    {
        qDebug() << str;
        vList->removeItem(spacer);
        SaveJson(str);
        vList->addItem(spacer);
    }

}


void WiFiRadioConfig::on_loadConfig_clicked()
{
    QString path = "/home/user/config_0.json";
    vList->removeItem(spacer);
    SaveJson(path);
    vList->addItem(spacer);
    getFile = false;

    QFile file(path); //lets get the file by filename
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))             //accessibility controll for file
    {
        qDebug() << "file open failure";   //send message if file cant open
    }
    QByteArray line;   //a qbytearray object for read file line by line
    while (!file.atEnd())
    {
        line.append(file.readLine());
    }
       //we read file line by line with no error handling for reading time!!

    file.close();
    QByteArray boundary;  //actually i cant understand that why we are using a second byte array for file sending.
// if someone know this trick please write below. I write this code like the other examples.

    QByteArray datas(QString("--" + boundary + "\r\n").toUtf8());
    datas += "Content-Disposition: form-data; name=\"file\"; filename=\"config.json\"\r\n";
//here is the http header for manuplate a normal http form and form file object

    datas += "Content-Type: text/x-chdr\r\n\r\n"; //file type is here
    datas += line; //and our file is giving to form object

    datas += "\r\n";
    datas += QString("--" + boundary + "\r\n\r\n").toUtf8();
    datas += "Content-Disposition: form-data; name=\"fupload\"\r\n\r\n";
    //datas += "Uploader\r\n";
    datas += QString("--" + boundary + "--\r\n").toUtf8();

    QNetworkRequest req;
    req.setUrl(QUrl(QString("http://%1/fupload").arg(ui->ipAddress->text())));    //my virtual servers' ip address and tiny php page url is here
    req.setRawHeader("Content-Type", "multipart/form-data; boundary=" + boundary);  // we must set the first header like this. its tell the server, current object is a form

    manager->post(req,datas); //send all data
}


void WiFiRadioConfig::onUpdatePos(double _lat, double _lon)
{
    qDebug() << "upd" << _lat << _lon;
    ui->weatherLat->setText(QString::number(_lat));
    ui->weatherLon->setText(QString::number(_lon));
    mapF->close();


}

void WiFiRadioConfig::on_openMap_clicked()
{
    if ( (ui->weatherLat->text() != "") || (ui->weatherLon->text() != ""))
        mapF = new MapForm(nullptr, ui->weatherLat->text().toDouble(), ui->weatherLon->text().toDouble());
    else mapF = new MapForm();
    connect(mapF, SIGNAL(updatePos(double, double)), this, SLOT(onUpdatePos(double, double)));
    mapF->show();


}

void WiFiRadioConfig::onTimerTout()
{
    QStringList parameters;
   #if defined(WIN32)
      parameters << "-n" << "1";
   #else
      parameters << "-c 1";
   #endif

      parameters << ui->ipAddress->text();

      int exitCode = QProcess::execute("ping", parameters);
      if (exitCode==0) {
          ui->connect->setText("Подключено");
          ui->loadConfig->setEnabled(true);
      } else {
          ui->connect->setText("Подключиться");
          ui->loadConfig->setEnabled(false);
          QPixmap pStat(":/images/statusDisconnect.svg");
          ui->status->setPixmap(pStat);
          timer->stop();
      }

}

void WiFiRadioConfig::onButtonPressed()
{
    dynamicButton *button = (dynamicButton*) sender();
    QString name = button->GetName();
    if (name.contains("showPasswd"))
    {
        ui->passwdWiFi->setEchoMode(QLineEdit::Normal);
    }
}

void WiFiRadioConfig::onButtonsClicked()
{
    dynamicButton *button = (dynamicButton*) sender();
    QString name = button->GetName();
    if (name.contains("open"))
    {
        QString strFilter="*.json";

        QString str = QFileDialog::getOpenFileName(0,
                                        "Открыть конфигурацию",
                                        "",
                                        "*.json",
                                        &strFilter
                                        );

        if (!str.isEmpty())
        {
            ui->configFile->setText(str);
        }

    } else if (name.contains("showPasswd"))
    {
        ui->passwdWiFi->setEchoMode(QLineEdit::Password);
    } else if (name.contains("findWiFi"))
    {
        searchNetworks = new WiFiSearch();
        connect(searchNetworks, SIGNAL(closeForm()), this, SLOT(onWiFiSearchFormClose()));
        connect(searchNetworks, SIGNAL(networkCLicked(QString)), this, SLOT(onWiFiClicked(QString)));

        searchNetworks->show();
    }
}

void WiFiRadioConfig::onWiFiSearchFormClose()
{
    disconnect(searchNetworks, SIGNAL(closeForm()), this, SLOT(onWiFiSearchFormClose()));
    disconnect(searchNetworks, SIGNAL(networkCLicked(QString)), this, SLOT(onWiFiClicked(QString)));
    searchNetworks = nullptr;
}

void WiFiRadioConfig::onWiFiClicked(QString ssid)
{
    ui->ssidWiFi->setText(ssid);
    searchNetworks->close();
}

