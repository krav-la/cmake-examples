import QtQuick 2.0
import QtQuick.Controls

Window {
    property bool showText: false

    id: root
    visible: true
    width: 400
    height: 400
    Button {
        width: 100
        height: 50
        id: showButton
        text: "Show"
        onClicked: {
            showText = showText == true ? false : true
            showButton.text = showText == true ? "Hide" : "Show"
        }
        anchors {
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }
    }
    Text {
        id: text
        visible: showText
        text: "Hello QML"
        font.pixelSize: 32
        anchors.centerIn: parent
    }
}