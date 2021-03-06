#ifndef DAYINFOCOLUMN_H
#define DAYINFOCOLUMN_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class DayInfoColumn;
}

class DayInfoColumn : public QWidget
{
    Q_OBJECT

public:
    typedef enum {
        INFO_ROW_1,
        INFO_ROW_2,
        INFO_ROW_3,
        INFO_ROW_4

     }InfoRowType;
public:
    explicit DayInfoColumn(QWidget *parent = 0);
    ~DayInfoColumn();

private:
    void setInfoRow(InfoRowType row,QString &txt);
    void setInfoRow(InfoRowType row,int arg1, int arg2);
    void setInfoRow(InfoRowType row,int arg1, int arg2);

    QLabel *getLable(InfoRowType label);

private:
    Ui::DayInfoColumn *ui;
};

#endif // DAYINFOCOLUMN_H
