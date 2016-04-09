#ifndef DAY_H
#define DAY_H

#include <QWidget>

namespace Ui {
class Day;
}

class Day : public QWidget
{
    Q_OBJECT

public:
    explicit Day(QWidget *parent = 0);
    ~Day();

private:
    Ui::Day *ui;
};

#endif // DAY_H
