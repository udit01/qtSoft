#ifndef ADDPOINT_H
#define ADDPOINT_H

#include <QWidget>

namespace Ui {
class addPoint;
}

class addPoint : public QWidget
{
    Q_OBJECT

public:
    explicit addPoint(QWidget *parent = 0);
    ~addPoint();

private:
    Ui::addPoint *ui;
};

#endif // ADDPOINT_H
