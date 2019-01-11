import QtQuick 2.0

Rectangle {
    id: root
    property string bgImage: ""
    property string content: ""
    property string bgColor: "#E0FFFF"
    property string ctFont: "Arial"
    property string ctFontColor: "#FFD700"
    property string ctImage: ""
    property int ctFontSize: 20

    color: bgImage != "" ? "transparent" : bgColor

    Image {
        id: bkgImage
        visible: bgImage != ""
        source: bgImage
    }

    onContentChanged:
    {
        console.log(content)
    }

    Text {
        id: txtCon
        text: content
        visible: ctImage == ""

        width: root.width - 40
        height: root.height - 20
        anchors.verticalCenter: root.verticalCenter
        anchors.horizontalCenter: root.horizontalCenter

        horizontalAlignment: Text.left
        verticalAlignment: Text.AlignVCenter
        color: ctFontColor
        font.pixelSize: ctFontSize
        wrapMode: Text.WordWrap

        Component.onCompleted: {
            console.log(txtCon.text)
        }
    }

    Image {
        id: contentImage
        visible: ctImage != ""
        source: ctImage
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
    }
}
