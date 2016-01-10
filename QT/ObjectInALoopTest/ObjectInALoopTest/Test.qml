
import QtQuick 2.0

Rectangle {
    id: base;
    width: 400;
    height: 800;

    Column {
        spacing: 5; // a simple layout do avoid overlapping

        Repeater {
            model: 10; // just define the number you want, can be a variable too


          delegate:  Rectangle {
                width: 200;
                height: 20;
                color: "white";
                border { width: 1; color: "black" }
                radius: 3;

                TextInput {
                    anchors.fill: parent;
                    text: index

                }
            }
        }
    }
}
