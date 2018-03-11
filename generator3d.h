#ifndef GENERATOR3D_H
#define GENERATOR3D_H

#include <QDialog>
#include "Model3d.hpp"
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>

namespace Ui {
class Generator3D;
}

class Generator3D : public QDialog
{
    Q_OBJECT

public:
    explicit Generator3D(QWidget *parent, QString filename);
    ~Generator3D();
    Model3d model3d;

private slots:
    void on_openImp_clicked();

    void on_addPoint_clicked();

private:
    Ui::Generator3D *ui;

};

#endif // GENERATOR3D_H
