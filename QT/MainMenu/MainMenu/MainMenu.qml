import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    property int menuScreenScaler
    property string  buttonText: ["Button 1" ,
                                  "Button 2" ,
                                  "Button 3" ,
                                  "Button 4" ,
                                  "Button 5" ,
                                  "Button 6" ,
                                  "Button 7" ,
                                  "Button 8" ,
                                  "Button 9" ,
                                  "Button 10"]
    property bool buttonVisibility: [true,
                                     true,
                                     true,
                                     true,
                                     true,
                                     true,
                                     true,
                                     true,
                                     true,
                                     true,]


    Column
    {
        id: row1
        anchors.fill: parent
        Button {
            id: button1
            visible: buttonVisibility[0]
            text: buttonText[0]
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id: button2
            visible: true
            text: "Button 2"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id:button3
            visible: true
            text: "Button 3"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id:button4
            visible: true
            text: "Button 4"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id:button5
            visible: true
            text: "Button 5"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id:button6
            visible: true
            text: "Button 6"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id:button7
            visible: true
            text: "Button 7"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id:button8
            visible: true
            text: "Button 8"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id:button9
            visible: true
            text: "Button 9"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }

        Button {
            id:button10
            visible: buttonVisibility[9]
            text: buttonText[9]
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
        }
    }
}
