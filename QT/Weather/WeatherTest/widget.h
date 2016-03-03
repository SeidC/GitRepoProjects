#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "weather.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private:
    Ui::Widget *ui;
    Weather weather;
    bool requestStatus;

public slots:
    void startRequest(bool clicked);
    void startWeather(bool clicked);
    void execAfterRequest(void);



};

#endif // WIDGET_H
