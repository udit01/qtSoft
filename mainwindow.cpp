#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "generator3d.h"
#include "generator2d.h"
#include <QFileDialog.h>
#include <QMessageBox>

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
    generator3D = new Generator3D(this);
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

    // if file is not null then open a new window base on extension else do nothing
    if(!file_name.isNull())
    {
        QMessageBox msgBox;
        msgBox.setText(file_name);
        msgBox.setInformativeText("Do you want to open this file?");
        msgBox.setStandardButtons(QMessageBox::Open | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Open);
        msgBox.setWindowTitle("Open Design");

        int ret = msgBox.exec();
        QChar ext;
        switch (ret) {
            case QMessageBox::Open:
                // opening a 2d/3d window based on extension
                ext = file_name[(file_name.length()-2)];

                hide();
                if(ext == '2')
                {
                    generator2D = new Generator2D(this, file_name);
                    generator2D -> show();
                }
                else if(ext == '3')
                {
                    generator3D = new Generator3D(this, file_name);
                    generator3D -> show();
                }
                else
                {
                    file_name = QString();
                }
                break;
            case QMessageBox::Discard:
                // do nothing if discarded
                file_name = QString();
                break;
            default:
                // should never be reached
                break;
        }
    }

}

