#ifndef TEXTEDITIF_H
#define TEXTEDITIF_H

#include <QObject>
#include <QTextEdit>
#include <QHostAddress>





class TextEditIf : public QObject
{
    Q_OBJECT
public:
    explicit TextEditIf(QObject *parent = 0);

    void setTextEdit(QTextEdit* sEdit = NULL);
    void clientConnected(void);
    void clientConnectionPending(void);
    void serverStarted(void);
    void setClientConfig(QHostAddress address, QString port);
    void setServerConfig(QString port);

private:
    void setText(QString txt);
private:
    QTextEdit* edit;
signals:

public slots:
};

#endif // TEXTEDITIF_H
