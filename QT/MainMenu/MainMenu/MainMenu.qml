import QtQuick 2.5
import QtQuick.Controls 1.4

Item
{
/*--- Alias Propertys ------------------------------------------------------------*/
    property alias          numberOfButtons: repeater.model


/*--- Propertys ------------------------------------------------------------------*/
    property int    menuScreenScaler: 4
    property var            buttonTextArray: []

/*--- Default Propertys ----------------------------------------------------------*/
    default property bool   autoDisableInvalidButton: true

    width: (parent.width / menuScreenScaler)
    height: parent.height
    visible: false

    signal onButtonClicked(string button)

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
                visible: disableInvalidButton(index)
                onClicked: onButtonClicked(index)
            }
        }
    }

    function setMainMenu()
    {
        if (this.visible === true)
        {
            this.visible = false
        }
        else
        {
            this.visible = true
        }
    }

    function getValidButtonText(index)
    {
        var buttonText = "Button" + (index + 1)
        if (index < numberOfButtons && buttonTextArray[index] !== undefined)
        {
            buttonText = buttonTextArray[index]
        }
        return buttonText
    }

    function disableInvalidButton(index)
    {
        var enable = true
        if(autoDisableInvalidButton === true)
        {
            if (buttonTextArray[index] === undefined)
            {
                enable = false
            }
        }
        return enable
    }

    function getButtonByIndex(index)
    {
        var i
        var button = undefined

        if(index < numberOfButtons && repeater.itemAt(index) !== undefined)
        {
            button = repeater.itemAt(index)
        }

        return button
    }

    function getButtonByText(buttonTxt)
    {
        var i
        var button = undefined
        for(i = 0; i < numberOfButtons; i ++)
        {
            if (repeater.itemAt(i).text === buttonTxt)
            {
                button = repeater.itemAt(i)
                break
            }
        }
        return button
    }
}
