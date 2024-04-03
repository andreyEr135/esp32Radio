#include "mapform.h"
#include "ui_mapform.h"

#include "MapGraphicsView.h"
#include "MapGraphicsScene.h"
#include "tileSources/GridTileSource.h"
#include "tileSources/OSMTileSource.h"
#include "tileSources/CompositeTileSource.h"
#include "guts/CompositeTileSourceConfigurationWidget.h"
#include "CircleObject.h"
#include "PolygonObject.h"

#include <QSharedPointer>
#include <QtDebug>
#include <QThread>
#include <QImage>

MapForm::MapForm(QWidget *parent, double _lat, double _lon) :
    QWidget(parent),
    ui(new Ui::MapForm)
{
    lat = _lat;
    if (lat == 0) lat = 55.755863;
    lon = _lon;
    if (lon == 0) lon = 37.6177;
    ui->setupUi(this);

    //Setup the MapGraphics scene and view
    MapGraphicsScene * scene = new MapGraphicsScene(this);
    MapGraphicsView * view = new MapGraphicsView(scene,this);

    view->setGeometry(0,0, this->width(), this->height());

    //Setup some tile sources
    QSharedPointer<OSMTileSource> osmTiles(new OSMTileSource(OSMTileSource::OSMTiles), &QObject::deleteLater);
    QSharedPointer<GridTileSource> gridTiles(new GridTileSource(), &QObject::deleteLater);
    QSharedPointer<CompositeTileSource> composite(new CompositeTileSource(), &QObject::deleteLater);
    composite->addSourceBottom(osmTiles);
    composite->addSourceTop(gridTiles);
    view->setTileSource(composite);

    view->setZoomLevel(12);
    view->centerOn(lon, lat);

    connect(view, SIGNAL(dClicked(QPointF)), this, SLOT(onDoubleClick(QPointF)));
}

MapForm::~MapForm()
{
    delete ui;
}

void MapForm::onDoubleClick(QPointF pos)
{
    qDebug() << "POS" << pos;
    lat = pos.y();
    lon = pos.x();
    emit updatePos(lat, lon);
    //this->close();
}
