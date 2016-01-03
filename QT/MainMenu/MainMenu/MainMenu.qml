import QtQuick 2.5
import QtQuick.Controls 1.4

Item
{
    property int menuScreenScaler
    property alias numberOfButtons: repeater.model
    property var buttonTextArray: []

    Column
    {
        id: itemColumn
        anchors.fill: parent
        Repeater
        {
            id: repeater
            Button {
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                text: getValidButtonText(index)
            }
        }
    }

    function getValidButtonText(index)
    {
        var buttonText = "Button" + index
        if (index < numberOfButtons)
        {
            buttonText = buttonTextArray[index]
        }
        return buttonText
    }
}
