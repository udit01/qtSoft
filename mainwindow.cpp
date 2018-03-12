#include <QFileDialog.h>
#include <QMessageBox>
#include <iostream>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "generator3d.h"
#include "generator2d.h"
#include "Model3d.hpp"

#include "Point.hpp"
#include "DirectionCosines.hpp"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openGen3d_clicked()
{
    // open in a new Window closing the current one
    hide();
    generator3D = new Generator3D(this, NULL);
    generator3D -> show();
}

void MainWindow::on_openGen2d_clicked()
{
    // open in a new Window closing the current one
    hide();
    generator2D = new Generator2D(this);
    generator2D -> show();
}

void MainWindow::on_openImp_clicked()
{
    // Opening import file dialog box
    QString file_name = QFileDialog::getOpenFileName(this, "Open a Design", ".");

    QChar ext;
    if(!file_name.isNull())
    {
        ext = file_name[(file_name.length()-2)];
    }

    // if file is not null then open a new window base on extension else do nothing
    if(!file_name.isNull() && (ext == '2' || ext == '3'))
    {
        QMessageBox msgBox;
        msgBox.setText(file_name);
        msgBox.setInformativeText("Do you want to open this file?");
        msgBox.setStandardButtons(QMessageBox::Open | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Open);
        msgBox.setWindowTitle("Open Design");

        int ret = msgBox.exec();

        switch (ret) {
            case QMessageBox::Open:
                // opening a 2d/3d window based on extension
                hide();
                if(ext == '2')
                {
                    generator2D = new Generator2D(this);
                    generator2D -> show();
                }
                else
                {
                    generator3D = new Generator3D(this, file_name);
                    generator3D -> show();
                }
                break;
            default:
                break;
        }
    }
}


void MainWindow::on_checkFunctions_clicked()
{
    Point p1 = Point(3.0,4.0,8.0);
    Point p2 = Point(5.0,8.0,3.0);
    DirectionCosines l1 = DirectionCosines(1.0, 2.0, 3.0);
    DirectionCosines l2 = DirectionCosines(1.0, -3.0, 4.0);
    DirectionCosines l3 = DirectionCosines(2.0, 4.0, -2.0);

}
