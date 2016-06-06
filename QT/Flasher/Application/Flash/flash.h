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
    void setConnections(void);


signals:
    void start(void);
    void cancle(void);

public slots:
    void showOrHideUi(void);
    void enableUi(void);
    void disableUi(void);
    void openDialog(void);
    void onStart(void);
    void onCancle(void);

private:
    Ui::Flash *ui;

};

#endif // FLASH_H
