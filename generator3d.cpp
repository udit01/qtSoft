#include "generator3d.h"
#include "ui_generator3d.h"
#include "Model3d.hpp"
#include <QFileDialog.h>
#include <QMessageBox>

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
    Model3d *model3d = new Model3d();
}

Generator3D::~Generator3D()
{
    delete ui;
}

void Generator3D::on_openImp_clicked()
{
    // Opening import file dialog box
    QString file_name = QFileDialog::getOpenFileName(this, "Open 3D Design", ".");

    // if file is not null then open a new window base on extension else do nothing
    if(!file_name.isNull())
    {
        QMessageBox msgBox;
        msgBox.setText(file_name);
        msgBox.setInformativeText("Do you want to open this file?");
        msgBox.setStandardButtons(QMessageBox::Open | QMessageBox::Discard);
        msgBox.setDefaultButton(QMessageBox::Open);
        msgBox.setWindowTitle("Open 3D Design");
        msgBox.setModal(true);

        int ret = msgBox.exec();
        QChar ext;
        switch (ret) {
            case QMessageBox::Open:
                // opening a 2d/3d window based on extension
                ext = file_name[(file_name.length()-2)];

                hide();
                if(ext != '3')
                {
                    file_name = QString();
                }
            case QMessageBox::Discard:
                file_name = QString();
                break;
            default:
                // should never be reached
                break;
        }
        if(!file_name.isNull())
        {
            Generator3D *generator3D = new Generator3D(this);
            generator3D -> (*model3d) = new Model3d(file_name.toLocal8Bit().constData());
            generator3D.setModal(true);
            generator3D.exec();
        }
    }
}
