#ifndef ADDPOINT3D_H
#define ADDPOINT3D_H

#include <QWidget>

namespace Ui {
class AddPoint3D;
}

class AddPoint3D : public QWidget
{
    Q_OBJECT

public:
    explicit AddPoint3D(QWidget *parent = 0);
    ~AddPoint3D();

private:
    Ui::AddPoint3D *ui;
};

#endif // ADDPOINT3D_H
