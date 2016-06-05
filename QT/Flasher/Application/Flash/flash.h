#ifndef FLASH_H
#define FLASH_H

#include <QWidget>

namespace Ui {
class Flash;
}

class Flash : public QWidget
{
    Q_OBJECT

public:
    explicit Flash(QWidget *parent = 0);
    ~Flash();

private:
    Ui::Flash *ui;
};

#endif // FLASH_H
