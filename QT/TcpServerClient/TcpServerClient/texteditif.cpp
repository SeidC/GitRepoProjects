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
    setText("Client Connected to Server");
    setText("........................");
    return;
}

void TextEditIf::clientConnectionPending()
{
    setText("Client connection pending....");
    setText("........................");
    return;
}

void TextEditIf::serverStarted(void)
{
    setText("Server Started");
    setText("........................");
    return;
}

void TextEditIf::setClientConfig(QHostAddress address, QString port)
{
    setText("Client Configuration:");
    setText("\tServeraddress: " + address.toString());
    setText("\tPort: " + port + "\n");
    return;
}

void TextEditIf::setServerConfig(QString port)
{
    setText("Server Configuration:");
    setText("\tPort: " + port + "\n");
    return;
}

void TextEditIf::setText(QString txt)
{
    edit->append(txt);
}

