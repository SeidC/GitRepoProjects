import QtQuick 2.0

Item {
    width: 320
    height: 120

    Rectangle {
        color: "green"
        width: 120
        height: 120

        // This is the behavior, and it applies a NumberAnimation to any attempt to set the x property
        Behavior on x {

            NumberAnimation {
                //This specifies how long the animation takes
                duration: 2000
                //This selects an easing curve to interpolate with, the default is Easing.Linear
                easing.type: Easing.InCubic
            }
        }

        Behavior on y {

            NumberAnimation {
                //This specifies how long the animation takes
                duration: 2000
                //This selects an easing curve to interpolate with, the default is Easing.Linear
                easing.type: Easing.InCubic
            }
        }

        onYChanged: {
                        if (y == 200)
                        {
                            x = 0
                            y = 400
                        }
                        console.log ("X = " + x + "\nY = " + y)
                    }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                            parent.x == 0 ? parent.x = 200 : parent.x = 0
                            parent.y == 0 ? parent.y = 200 : parent.y = 0
                       }
        }
    }
}
