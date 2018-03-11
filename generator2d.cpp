#include "generator2d.h"
#include "ui_generator2d.h"

Generator2D::Generator2D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generator2D)
{
    ui->setupUi(this);
}

//Generator2D::Generator2D(QWidget *parent, QString filename) :
//    QDialog(parent),
//    ui(new Ui::Generator2D)
//{
//    ui->setupUi(this);
//}

Generator2D::~Generator2D()
{
    delete ui;
}


