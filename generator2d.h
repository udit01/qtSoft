#ifndef GENERATOR2D_H
#define GENERATOR2D_H

#include <QDialog>

namespace Ui {
class Generator2D;
}

class Generator2D : public QDialog
{
    Q_OBJECT

public:
    explicit Generator2D(QWidget *parent);
    //explicit Generator2D(QWidget *parent, QString filename);
    ~Generator2D();

private:
    Ui::Generator2D *ui;
};

#endif // GENERATOR2D_H
