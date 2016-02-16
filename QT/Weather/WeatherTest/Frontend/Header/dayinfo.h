#ifndef DAYINFO_H
#define DAYINFO_H

#include <QWidget>

namespace Ui {
class DayInfo;
}

class DayInfo : public QWidget
{
    Q_OBJECT

public:
    explicit DayInfo(QWidget *parent = 0);
    ~DayInfo();

private:
    Ui::DayInfo *ui;
};

#endif // DAYINFO_H
