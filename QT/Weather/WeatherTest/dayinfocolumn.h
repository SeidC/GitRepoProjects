#ifndef DAYINFOCOLUMN_H
#define DAYINFOCOLUMN_H

#include <QWidget>

namespace Ui {
class DayInfoColumn;
}

class DayInfoColumn : public QWidget
{
    Q_OBJECT

public:
    explicit DayInfoColumn(QWidget *parent = 0);
    ~DayInfoColumn();

private:
    Ui::DayInfoColumn *ui;
};

#endif // DAYINFOCOLUMN_H
