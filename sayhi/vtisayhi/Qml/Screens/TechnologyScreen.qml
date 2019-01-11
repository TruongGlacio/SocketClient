import QtQuick 2.12
import VTIEnum 1.1
import "../Common"
import "../JS/Constants.js" as Constants

Image {
    source: Constants.BACKGROUND_IMAGE_PATH
    width: 1920
    height: 1080

    Component.onCompleted: {
        TechScrModel.title = "Technology"
    }

    Image {
        id: header
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top:  parent.top
        anchors.topMargin: 45
        source: "../Images/Technology/areatitle.png"
        width: 1920
        height: 97
    }

    Text{
        id: headerTID
        text: TechScrModel.title
        anchors.centerIn: header
        color: "yellow"
        font.bold: true
        font.pixelSize: 60
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

//    Rectangle {
//        anchors.fill: headerTID
//        color: "red"
//        opacity: 0.3
//    }

//    MouseArea {
//        anchors.fill: headerTID
//        hoverEnabled: true

//        onContainsMouseChanged: {
//            btnAI.isShown = containsMouse
//        }

//        onEntered: {
//            btnAI.isShown = true
//            console.log("btnAI.isShown = " + btnAI.isShown)
//        }

//        onExited: {
//            btnAI.isShown = false
//            console.log("btnAI.isShown = " + btnAI.isShown)
//        }
//    }

    ButtonCommon {
        id: btnAI
        anchors.left: parent.left
        anchors.leftMargin: 36
        anchors.top:  parent.top
        anchors.topMargin: 323
        width: 425
        height: 300
        innerText: qsTr("AI")
        fontSize: Constants.BUTTON_TEXT_FONTSIZE_DEFAULT
//        isModeSH: true
        bkgImagePress: Constants.TECH_BUTTON_TL_P_IMAGE_PATH
        bkgImageNormal: Constants.TECH_BUTTON_TL_N_IMAGE_PATH
        bkgImageHover: Constants.TECH_BUTTON_TL_H_IMAGE_PATH
        onBtnClicked: {
            ScreenManager.reqGoTo(VTIEnum.ScreenTechnologyDetails);
            TechScrModel.title = "AI"
        }
    }

    ButtonCommon {
        id: btnIOT
        anchors.left: parent.left
        anchors.leftMargin: 495
        anchors.top:  parent.top
        anchors.topMargin: 323
        width: 425
        height: 300
        innerText: qsTr("IOT")
        fontSize: Constants.BUTTON_TEXT_FONTSIZE_DEFAULT
        bkgImagePress: Constants.TECH_BUTTON_TR_P_IMAGE_PATH
        bkgImageNormal: Constants.TECH_BUTTON_TR_N_IMAGE_PATH
        bkgImageHover: Constants.TECH_BUTTON_TR_H_IMAGE_PATH
        onBtnClicked: {
            ScreenManager.reqGoTo(VTIEnum.ScreenTechnologyDetails);
            TechScrModel.title = "IOT"
        }
    }

    ButtonCommon {
        id: btnCLOUD
        anchors.left: parent.left
        anchors.leftMargin: 36
        anchors.top:  parent.top
        anchors.topMargin: 660
        width: 425
        height: 300
        innerText: qsTr("Cloud")
        fontSize: Constants.BUTTON_TEXT_FONTSIZE_DEFAULT
        bkgImagePress: Constants.TECH_BUTTON_BL_P_IMAGE_PATH
        bkgImageNormal: Constants.TECH_BUTTON_BL_N_IMAGE_PATH
        bkgImageHover: Constants.TECH_BUTTON_BL_H_IMAGE_PATH
        onBtnClicked: {
            ScreenManager.reqGoTo(VTIEnum.ScreenTechnologyDetails);
            TechScrModel.title = "Cloud"
        }
    }

    ButtonCommon {
        id: btnEm
        anchors.left: parent.left
        anchors.leftMargin: 495
        anchors.top:  parent.top
        anchors.topMargin: 660
        width: 425
        height: 300
        innerText: qsTr("Embedded")
        fontSize: Constants.BUTTON_TEXT_FONTSIZE_DEFAULT
        bkgImagePress: Constants.TECH_BUTTON_BR_P_IMAGE_PATH
        bkgImageNormal: Constants.TECH_BUTTON_BR_N_IMAGE_PATH
        bkgImageHover: Constants.TECH_BUTTON_BR_H_IMAGE_PATH
        onBtnClicked: {
            ScreenManager.reqGoTo(VTIEnum.ScreenTechnologyDetails);
            TechScrModel.title = "Embedded"
        }
    }

    UIContent {
        id: whatarea
        anchors.left: parent.left
        anchors.leftMargin: 994
        anchors.top:  parent.top
        anchors.topMargin: 323
        bgImage: Constants.TECH_BKG_CONTENT_RIGHT_IMAGE_PATH
        ctImage: TechScrModel.techInfoPath
    }

    Image {
        id: headContB
        anchors.left: parent.left
        anchors.leftMargin: 1061
        anchors.top:  parent.top
        anchors.topMargin: 277
        width: 357
        height: 104
        source: Constants.TECH_LABEL_WHAT_IMAGE_PATH
        Text {
            id: headCont
            anchors.centerIn: parent
            text: qsTr("What we do")
            font.pixelSize: Constants.TEXT_FONTSIZE_DEFAULT
        }
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
