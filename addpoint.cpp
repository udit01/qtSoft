#include "addpoint.h"
#include "ui_addpoint.h"

addPoint::addPoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addPoint)
{
    ui->setupUi(this);
}

addPoint::~addPoint()
{
    delete ui;
}
