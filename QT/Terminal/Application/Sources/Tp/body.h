#ifndef BODY_H
#define BODY_H

#include <QWidget>

class Body : public QWidget
{
    Q_OBJECT
public:
    explicit Body(QWidget *parent = 0);

    int getLength() const;
    void setLength(int value);

    QByteArray *getData() const;
    void setData(QByteArray *value);

private:
    int length;
    QByteArray *data;

signals:

public slots:
};

#endif // BODY_H
