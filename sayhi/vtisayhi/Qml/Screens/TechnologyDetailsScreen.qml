import QtQuick 2.12
import VTIEnum 1.1
import "../Common"
import "../JS/Constants.js" as Constants

Image {
    source: Constants.BACKGROUND_IMAGE_PATH
    width: 1920
    height: 1080

    Text{
        text: TechScrModel.title
        anchors.left: parent.left
        anchors.leftMargin: 42
        anchors.top:  parent.top
        anchors.topMargin: 30
        width: 161
        height: 120
        color: "yellow"
        font.bold: true
        font.pixelSize: 60
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Image {
        id: shape_1
        source: Constants.DETAIL_HEADER_BKG_UP_IMAGE_PATH
        x: 342
        y: 70
    }
    Image {
        id: shape_1_copy
        source: Constants.DETAIL_HEADER_BKG_DOWN_IMAGE_PATH
        x: 404
        y: 91
    }

    UIContent {
        anchors.left: parent.left
        anchors.leftMargin: 42
        anchors.top:  parent.top
        anchors.topMargin: 143
        width: 903
        height: 848
        content: TechScrModel.techDeConLeft
        bgImage: Constants.DETAIL_BKG_LEFT_IMAGE_PATH
    }

    UIContent {
        anchors.left: parent.left
        anchors.leftMargin: 973
        anchors.top:  parent.top
        anchors.topMargin: 143
        width: 903
        height: 614
        content: TechScrModel.techDeConRight
        bgImage: Constants.DETAIL_BKG_RIGHT_IMAGE_PATH
    }

    Text{
        text: "Description"
        anchors.left: parent.left
        anchors.leftMargin: 1010
        anchors.top:  parent.top
        anchors.topMargin: 910
        width: 250
        height: 100
        color: "#00FF84"
        font.bold: true
        font.pixelSize: 60
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    ButtonCommon {
        anchors.left: parent.left
        anchors.leftMargin: 755
        anchors.top:  parent.top
        anchors.topMargin: 1026
        width: 409
        height: 53
        innerText: qsTr("Home")
        fontSize: Constants.BUTTON_HOME_FONTSIZE_DEFAULT
        bkgImagePress: Constants.BUTTON_HOME_P_IMAGE_PATH
        bkgImageNormal: Constants.BUTTON_HOME_N_IMAGE_PATH
        bkgImageHover: Constants.BUTTON_HOME_H_IMAGE_PATH
        onBtnClicked: {
            ScreenManager.reqGoTo(VTIEnum.ScreenStandby);
        }
    }
}
