#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

private:
    void disableServerSettings(void);
    void enableServerSettings(void);

    bool startServer(void);
    bool startClient(void);
    bool stopServer(void);
    bool stopClient(void);


public slots:
    void networkComboIndexChanged(QString name);
    void exit(void);
    void appButtonClicked(void);
};

#endif // WIDGET_H
