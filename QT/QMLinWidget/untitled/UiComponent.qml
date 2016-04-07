import QtQuick 2.0
import QtQuick.Extras 1.4

Item {
    z: 20
    clip: false

    DelayButton {
        id: delayButton1
        text: qsTr("Button")
        anchors.fill: parent
        onActivated: text = "I Was Clicked"

    }
}
