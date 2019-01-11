import QtQuick 2.12
import VTIEnum 1.1
import "../Common"
import "../JS/Constants.js" as Constants

Image {
    source: Constants.BACKGROUND_IMAGE_PATH
    width: 1920
    height: 1080

    Component.onCompleted: {
        timeChangeScr.start()
    }

    Image {
        id: header
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.verticalCenter: parent.verticalCenter
        source: Constants.START_HEADER_BKG_IMAGE_PATH
        width: 1920
        height: 97
    }

    Text{
        id: headerTID
        text: StartScrModel.title
        anchors.centerIn: header
        color: "yellow"
        font.bold: true
        font.pixelSize: 60
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Timer {
        id: timeChangeScr
        interval: 3000
        repeat: false
        running: false
        onTriggered: {
            ScreenManager.reqGoTo(VTIEnum.ScreenStandby);
            timeChangeScr.stop()
        }
    }
}
