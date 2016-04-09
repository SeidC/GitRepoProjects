#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QList>


class Test;

typedef QList<Test> TestList;


class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = 0);

signals:

public slots:
};

#endif // TEST_H
