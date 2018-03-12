#include "generator3d.h"
#include "ui_generator3d.h"
#include "addpoint.h"
#include "Model3d.hpp"
#include <QFileDialog.h>
#include <QMessageBox>

Generator3D::Generator3D(QWidget *parent, QString filename) :
    QDialog(parent),
    ui(new Ui::Generator3D)
{
    ui->setupUi(this);
    if(!filename.isNull())
    {
       model3d = Model3d::deserialize(filename.toStdString());
    }
    else
    {
       model3d = Model3d();
    }

}

Generator3D::~Generator3D()
{
    delete ui;
}

void Generator3D::on_openImp_clicked()
{
    // Opening import file dialog box
    QString file_name = QFileDialog::getOpenFileName(this, "Open a Design", ".");

    QChar ext;
    if(!file_name.isNull())
    {
        ext = file_name[(file_name.length()-2)];
    }

    // if file is not null then open a new window base on extension else do nothing
    if(!file_name.isNull() && ext == '3')
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
                // set model3d with filename
                model3d = Model3d::deserialize(file_name.toStdString());
                this -> show();
                break;
            default:
                break;
        }
    }
}

void Generator3D::on_addPoint_clicked()
{
        //Creating a new list widget item whose parent is the listwidget itself
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui -> listPoints);

        //Adding the item to the listwidget
        ui -> listPoints -> addItem (listWidgetItem);

        //Creating an object of the designed widget which is to be added to the listwidget
        addPoint *theWidgetItem = new addPoint;

        //Making sure that the listWidgetItem has the same size as the TheWidgetItem
        listWidgetItem -> setSizeHint (theWidgetItem -> sizeHint());

        //Finally adding the itemWidget to the list
        ui -> listPoints -> setItemWidget (listWidgetItem, theWidgetItem);
}
