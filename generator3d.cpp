#include "generator3d.h"
#include "ui_generator3d.h"

Generator3D::Generator3D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generator3D)
{
    ui->setupUi(this);
}


Generator3D::Generator3D(QWidget *parent, QString filename) :
    QDialog(parent),
    ui(new Ui::Generator3D)
{
    ui->setupUi(this);
}

Generator3D::~Generator3D()
{
    delete ui;
}
