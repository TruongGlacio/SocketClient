import QtQuick 2.0

Item {
    id: idPhptoPlayer
    property string imagePath: ""
    property bool isNextPrevButtonEnabled: true
    signal playPrev
    signal playNext

    Image {
        id: idImage
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        source: parent.imagePath
        fillMode: Image.PreserveAspectFit
        asynchronous: true
    }

    LeftRightPanel{
        id: idLeftPanel
        x: 0
        y: 0
        width: parent.width/5
        height: parent.height
        isPreviousBtn: true
        visible: parent.isNextPrevButtonEnabled

        onPanelClicked: {
            console.log("PhotoPlayer - PlayPrev")
            parent.playPrev()
        }
    }

    LeftRightPanel{
        id: idRightPanel
        x: parent.width*4/5
        y: 0
        width: parent.width/5
        height: parent.height
        isPreviousBtn: false
        visible: parent.isNextPrevButtonEnabled

        onPanelClicked: {
            console.log("PhotoPlayer - PlayNext")
            parent.playNext()
        }

    }

}
