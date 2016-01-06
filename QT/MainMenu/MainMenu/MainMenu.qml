import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item
{
/*--- Alias Propertys ------------------------------------------------------------*/
    property alias numberOfButtons: itemRepeater.model
    property alias menuButtonSpacing: itemColumn.spacing

/*--- Propertys ------------------------------------------------------------------*/

    property var buttonTextArray: []
    property bool autoDisableInvalidButton: true
    property int menuScreenScaler: 4

    property bool menuAntialiasing: false
/*--- Color Propertys ------------------------------------------------------------*/
    property color menuColor: "grey"
    property color menuButtonColor: "grey"

    property color menuBorderColor : "grey"
    property color menuButtonBorderColor : "black"

/*--- Border Propertys -----------------------------------------------------------*/
    property int menuBorderWidth:0
    property int menuButtonBorderWidth: 2


/*--- Signals --------------------------------------------------------------------*/
    signal buttonClickedS(string button)
    signal buttonClickedI(int button)

/*--- Interal Object Propertys ---------------------------------------------------*/
    width: (parent.width / menuScreenScaler)
    height: parent.height
    visible: false
    z: 200

    Rectangle {
        id: itemRectangle
        color: menuColor
        anchors.fill: parent
        antialiasing: menuAntialiasing
        border.color: menuBorderColor
        border.width: menuBorderWidth

        Column
        {
            id: itemColumn
            anchors.fill: parent
            Repeater
            {
                id: itemRepeater
                Button
                {
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    style:  ButtonStyle
                    {
                        background: Rectangle
                        {
                            color: menuButtonColor
                            border.width: menuButtonBorderWidth
                            border.color: menuButtonBorderColor

                        }
                    }

                    text: getValidButtonText(index)
                    visible: disableInvalidButton(index)
                    antialiasing: menuAntialiasing
                    onClicked: {
                                    buttonClickedS(getValidButtonText(index))
                                    buttonClickedI(index)
                               }
                }
            }
        }
     }

/****************************************************************************
 *
 ****************************************************************************/
    function setMainMenu()
    {
        if (this.visible === true)
        {
            this.visible = false;
        }
        else
        {
            this.visible = true;
        }
    }

/****************************************************************************
 *
 ****************************************************************************/
    function getValidButtonText(index)
    {
        var buttonText = "Button" + (index + 1);
        if (index < numberOfButtons && buttonTextArray[index] !== undefined)
        {
            buttonText = buttonTextArray[index];
        }
        return buttonText;
    }

/****************************************************************************
 *
 ****************************************************************************/
    function disableInvalidButton(index)
    {
        var enable = true;
        if(autoDisableInvalidButton === true)
        {
            if (buttonTextArray[index] === undefined)
            {
                enable = false;
            }
        }
        return enable;
    }

/****************************************************************************
 *
 ****************************************************************************/
    function getButtonByIndex(index)
    {
        var i;
        var button = undefined;

        if(index < numberOfButtons && itemRepeater.itemAt(index) !== undefined)
        {
            button = itemRepeater.itemAt(index);
        }
        return button;
    }

/****************************************************************************
 *
 ****************************************************************************/
    function getButtonByText(buttonTxt)
    {
        var i
        var button = undefined;
        for(i = 0; i < numberOfButtons; i ++)
        {
            if (itemRepeater.itemAt(i).text === buttonTxt)
            {
                button = itemRepeater.itemAt(i);
                break;
            }
        }
        return button;
    }
}
