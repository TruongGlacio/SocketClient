import QtQuick 2.12
import "../JS/Constants.js" as Constants
Item {
    id: idButton

    property string bkgImageNormal: ""
    property string bkgImageHover: ""
    property string bkgImagePress: ""
    property string innerText: ""
    property int fontSize: 30
    property int fontSizeHover: fontSize + 8
    property int fontSizePress: fontSize + 8
    property string fontColor: "#40E0D0"
    property string fontColorHover: "#AFEEEE"
    property string fontColorPress: "#E0FFFF"
    property bool isModeSH: false
    property bool isShown: false

    signal btnClicked()

    Image {
        id: idBackground
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        source: idMouseArea.pressed ? bkgImagePress : (idMouseArea.containsMouse ? bkgImageHover : bkgImageNormal)
        visible: isModeSH ? (idMouseArea.containsMouse || idButton.isShown ? true : false) : true
    }

    Text {
        id: idInnerText
        anchors.centerIn: parent
        font.pixelSize: idMouseArea.pressed ? fontSizePress : (idMouseArea.containsMouse ? fontSizeHover : fontSize)
        color: idMouseArea.pressed ? fontColorPress : (idMouseArea.containsMouse ? fontColorHover : fontColor)
        text: parent.innerText
        visible: isModeSH ? (idMouseArea.containsMouse || idButton.isShown ? true : false) : true
    }

    MouseArea {
        id: idMouseArea
        anchors.fill: parent
        hoverEnabled: true

        onEntered:{
            idMouseTimer.start()
		}

        onClicked: {
            if (idBackground.visible)
            {
                parent.btnClicked()
            }
            idMouseTimer.stop()
            mouse.accepted = false
        }
    }

    Timer{
        id: idMouseTimer
        interval: Constants.MOUSE_PRESS_TIMER
        repeat: false

        onTriggered: {
            console.log("ButtonCommon - parent.clicked")
            parent.btnClicked()
        }
    }
}
