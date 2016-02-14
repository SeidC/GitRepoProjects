#ifndef DAYGRAPHIC_H
#define DAYGRAPHIC_H

#include <QWidget>

namespace Ui {
class DayGraphic;
}

class DayGraphic : public QWidget
{
    Q_OBJECT

public:
    explicit DayGraphic(QWidget *parent = 0);
    ~DayGraphic();

private:
    Ui::DayGraphic *ui;
};

#endif // DAYGRAPHIC_H
