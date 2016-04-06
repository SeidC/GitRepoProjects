#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "weather.h"
#include <QComboBox>

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
    void deleteCombobox(QComboBox *combo);
private:
    Ui::Widget *ui;
    Weather weather;
    bool requestStatus;

public slots:
    void startRequest(bool clicked);
    void startWeather(bool clicked);
    void onCountryChanged(QString country);
    void execAfterRequest(void);



};

#endif // WIDGET_H
