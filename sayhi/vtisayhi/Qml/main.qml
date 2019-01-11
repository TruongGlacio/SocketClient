import QtQuick 2.9
import QtQuick.Window 2.2
import VTIEnum 1.1
import "Common"
import "JS/Constants.js" as Constants
Window {
    visible: true
    width:1920
    height:1080
    flags: Qt.Window | Qt.FramelessWindowHint
    color: "green"

//    PhotoPlayer{
//        id:idPhotoPlayer
//        anchors.fill: parent
//        imagePath: "qrc:/Qml/Images/Standby/background.png"
//    }

    Loader {
        id: idLoaderFirst
        anchors.fill: parent
        source: ""
        onLoaded: {
            idLoaderFirst.visible = true
            idLoaderSecond.source = ""
            idLoaderSecond.visible = false
        }
    }

    Loader {
        id: idLoaderSecond
        anchors.fill: parent
        source: ""
        onLoaded: {
            idLoaderSecond.visible = true
            idLoaderFirst.source = ""
            idLoaderFirst.visible = false
        }
    }

    function switchLoader(pathComponent)
    {
        if(idLoaderFirst.source == "")
        {
            idLoaderFirst.setSource(pathComponent)
        }else {
            idLoaderSecond.setSource(pathComponent)
        }
    }

    Component.onCompleted: {
        timeChangeScr.start()
    }

//    MouseArea {
//        id: testMouse
//        anchors.fill: parent
//        onClicked: {
//            ScreenManager.reqGoTo(VTIEnum.ScreenStartup);
//            testMouse.enabled = false
//        }
//    }

    Timer {
        id: timeChangeScr
        interval: 1000
        repeat: false
        running: false
        onTriggered: {
            ScreenManager.reqGoTo(VTIEnum.ScreenStartup);
            timeChangeScr.stop()
        }
    }
}
