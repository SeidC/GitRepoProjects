#ifndef FLASH_H
#define FLASH_H

#include <QWidget>
#include <QString>

namespace Ui {
class Flash;
}

class Flash : public QWidget
{
    Q_OBJECT
public:
    struct FlashSettings_t
    {
        bool    useCrc;
        bool    useSqc;
        uint    tpLength;
        QString path;

    };


public:
    explicit Flash(QWidget *parent = 0);
    ~Flash();
    FlashSettings_t getSettings(void);

private:
    void setConnections(void);
    void updateSettings(void);

private:
    FlashSettings_t settings;

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
