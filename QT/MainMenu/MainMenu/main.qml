import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    toolBar: ToolBar {
            RowLayout {
                ToolButton {
                    id: mainMenuButton
                    iconSource: "new.png"
                    onClicked: mainMenu.setMainMenu()
                }
                ToolButton {
                    iconSource: "open.png"
                }
                ToolButton {
                    iconSource: "save-as.png"
                }
                Item { Layout.fillWidth: true }
                CheckBox {
                    text: "Enabled"
                    checked: true
                }
            }
       }
    MainMenu {
        id: mainMenu
        numberOfButtons: 3
        buttonTextArray: ["Test 1 ", "Test 2"]
        onButtonClickedS: { console.log("Button with Name: " + button) }
        onButtonClickedI: {console.log("Button with Name: " + button) }

    }

    MainForm {
        anchors.fill: parent
        button1.onClicked: messageDialog.show(qsTr("Button 1 pressed"))
        button2.onClicked: messageDialog.show(qsTr("Button 2 pressed"))

    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
