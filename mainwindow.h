#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "generator2d.h"
#include "generator3d.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openGen3d_clicked();

    void on_openGen2d_clicked();

    void on_openImp_clicked();

private:
    Ui::MainWindow *ui;
    Generator2D *generator2D;
    Generator3D *generator3D;
};

#endif // MAINWINDOW_H
