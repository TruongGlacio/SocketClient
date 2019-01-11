import QtQuick 2.12
import VTIEnum 1.1
import "../Common"
import "../JS/Constants.js" as Constants

Image {
    source: Constants.BACKGROUND_IMAGE_PATH
    width: 1920
    height: 1080

    UIContent {
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.top:  parent.top
        anchors.topMargin: 27
        width: 918
        height: 1027
        ctImage: NewsScrModel.leftContent
        bgImage: Constants.NEWS_BKG_LEFT_IMAGE_PATH
    }

    UIContent {
        anchors.left: parent.left
        anchors.leftMargin: 974
        anchors.top:  parent.top
        anchors.topMargin: 27
        width: 918
        height: 1027
        ctImage: NewsScrModel.rightContent
        bgImage: Constants.NEWS_BKG_RIGHT_IMAGE_PATH
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
        isModeSH: true
        onBtnClicked: {
            ScreenManager.reqGoTo(VTIEnum.ScreenStandby);
        }
    }
}
