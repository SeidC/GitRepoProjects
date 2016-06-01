/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "console.h"

#include <QScrollBar>
#include <QStringList>
#include <QtCore/QDebug>

Console::Console(QWidget *parent)
    : QTableWidget(parent)
    , localEchoEnabled(false)
{
    headerColums = new QList<QTableWidgetItem*>();
    headerColums->push_back(new QTableWidgetItem("Time",0));
    headerColums->push_back(new QTableWidgetItem("ID",0));
    headerColums->push_back(new QTableWidgetItem("DIR",0));
    headerColums->push_back(new QTableWidgetItem("Data",0));

    msgTimer = new QTimer();

    statusOutputLabel = NULL;

    setColumnCount(headerColums->size());

    for(int i = 0; i < headerColums->size(); i++)
    {
        setHorizontalHeaderItem(i,headerColums->at(i));
    }

    //document()->setMaximumBlockCount(100);
    QPalette p = palette();
    //p.setColor(QPalette::Base, Qt::black);
    //p.setColor(QPalette::Text, Qt::green);
    setPalette(p);

    msgHandler = new TpHandler();

    connect(msgHandler,SIGNAL(tpMessageReceived()),this,SLOT(tpMessageReceived()));
    connect(msgHandler,SIGNAL(tpMessageError(TpHandler::Error_t)),this,SLOT(tpError(TpHandler::Error_t)));

}

void Console::putData(const QByteArray &data)
{
    msgHandler->putData(data);
    QScrollBar *bar = verticalScrollBar();
    bar->setValue(bar->maximum());
}

void Console::setLocalEchoEnabled(bool set)
{
    localEchoEnabled = set;
}

void Console::addNewRow(void)
{
//    setRowCount(rowCount() + 1);
//    for(int i = 0;i < columnCount(); i++)
//    {
//        setItem(rowCount(),i,new QTableWidgetItem());
//    }
    emit addRow(rowCount() + 1);
    return;
}

void Console::setOutputLable(QLabel *statusOutput)
{
    statusOutputLabel = statusOutput;
}

void Console::keyPressEvent(QKeyEvent *e)
{
//    switch (e->key()) {
//    case Qt::Key_Backspace:
//    case Qt::Key_Left:
//    case Qt::Key_Right:
//    case Qt::Key_Up:
//    case Qt::Key_Down:
//        break;
//    default:
//        if (localEchoEnabled)
//            QPlainTextEdit::keyPressEvent(e);
//        emit getData(e->text().toLocal8Bit());
//    }
}

void Console::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    setFocus();
}

void Console::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
}

void Console::contextMenuEvent(QContextMenuEvent *e)
{
    Q_UNUSED(e)
}

void Console::tpMessageReceived(void)
{
    TP* tp = msgHandler->getLastReceivedMessage();
    setData(tp);
    return;
}

void Console::tpError(TpHandler::Error_t error)
{
    QString message;
    message = "Error in ";
    switch(error)
    {
        case TpHandler::START_SIGN_ERROR  :
            message += "START SIGN Field";
        break;
        case TpHandler::ID_ERROR          :
            message += "ID Field";
        break;
        case TpHandler::BODY_SIZE_ERROR   :
            message += "BODY SIZE Field";
        break;
        case TpHandler::MESSAGE_DATA_ERROR:
            message += "MESSAGE DATA Field";
        break;
        case TpHandler::SQC_ERROR         :
            message += "SQC Field";
        break;
        case TpHandler::CRC_ERROR         :
            message += "CRC Field";
        break;
        case TpHandler::STOP_SIGN_ERROR   :
            message += "STOP SIGN Field";
        break;
        case TpHandler::DATA_TIMEOUT:
            message = "Data Timeout Error!!";
        break;
        default:
            message = "Unkown Error";
    }
    showStatusMessage(message);
    return;
}



void Console::showStatusMessage(const QString &message)
{
    if(statusOutputLabel != NULL)
        statusOutputLabel->setText(message);
}

void Console::setData(TP *msg)
{
    int row;
    QString id("0x" + QString::number(msg->getId(),16));
    QString dir("Rx");
    QString data = byteArrayToHexString(*msg->getData());
    row = rowCount();
    setRowCount(row + 1);
    setItem(row,1,new QTableWidgetItem(id,0));
    setItem(row,2,new QTableWidgetItem(dir,0));
    setItem(row,3,new QTableWidgetItem(data,0));

    return;
}


QString Console::byteArrayToHexString(QByteArray &data)
{
    QString ret;
    for(int i = 0; i < data.size(); i++)
    {
        ret += "0x" + QString::number(data.at(i),16) + " ";
    }
    return ret;
}
