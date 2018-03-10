#ifndef GENERATOR3D_H
#define GENERATOR3D_H

#include <QDialog>

namespace Ui {
class Generator3D;
}

class Generator3D : public QDialog
{
    Q_OBJECT

public:
    explicit Generator3D(QWidget *parent);
    explicit Generator3D(QWidget *parent, QString filename);
    ~Generator3D();

private:
    Ui::Generator3D *ui;
};

#endif // GENERATOR3D_H
