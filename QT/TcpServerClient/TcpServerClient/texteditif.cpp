#include "texteditif.h"

TextEditIf::TextEditIf(QObject *parent) : QObject(parent)
{
    edit = NULL;
}

void TextEditIf::setTextEdit(QTextEdit *sEdit)
{
    if(sEdit != NULL)
    {
        edit = sEdit;
    }
    return;
}

void TextEditIf::clientConnected(void)
{
    setText("Client Connected to Server \n");
    return;
}

void TextEditIf::serverStarted(void)
{
    setText("Server Started\n");
}

void TextEditIf::setClientConfig(QHostAddress address, qint16 port)
{
    char buffer[5];
    QString res;
    itoa(port,buffer,10);
    res += buffer;
    setText("Client Configuration: \n");
    setText("Serveraddress: " + address.toString() + "\n");
    setText("Port: " + res + "\n");
}

void TextEditIf::setServerConfig(qint16 port)
{
    char buffer[5];
    QString res;
    itoa(port,buffer,10);
    res += buffer;
    setText("Server Configuration: \n");
    setText("Port: " + res + "\n");
}

void TextEditIf::setText(QString txt)
{
    edit->append(txt);
}

