import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import "../JS/Constants.js" as Constants

Item {
    id: idLeftRightPanel

    property bool showBtn: false
    property bool isBtnVisible: false
    property bool isPreviousBtn: true

    signal panelClicked

    MouseArea{
        id: idLeftRightPanelMouseArea
        anchors.fill: parent
        hoverEnabled: true

        onContainsMouseChanged: {
            idInnerBtn.isShown = containsMouse
        }
    }

    ButtonCommon {
        id: idInnerBtn
        width: Constants.LEFT_RIGHT_BUTTON_WIDTH
        height: Constants.LEFT_RIGHT_BUTTON_WIDTH
        anchors.centerIn: parent
        bkgImageNormal: isPreviousBtn ? Constants.PRE_BUTTON_IMAGE_NORMAL_PATH : Constants.NEXT_BUTTON_IMAGE_NORMAL_PATH
        bkgImageHover: isPreviousBtn ? Constants.PRE_BUTTON_IMAGE_HOVER_PATH : Constants.NEXT_BUTTON_IMAGE_HOVER_PATH
        bkgImagePress: isPreviousBtn ? Constants.PRE_BUTTON_IMAGE_PRESS_PATH : Constants.NEXT_BUTTON_IMAGE_HOVER_PATH
        isModeSH: true

        onBtnClicked: {
            parent.panelClicked()
        }

//        onHovered: {
//            console.log("ButtonCommon onHovered")
//            parent.isBtnVisible = true
//        }

//        onExited: {
//            console.log("ButtonCommon onExited")
//            parent.isBtnVisible = false
//        }
    }

}

