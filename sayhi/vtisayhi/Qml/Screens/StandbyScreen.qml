import QtQuick 2.0
import QtMultimedia 5.8
import "../Common"
import "../JS/Constants.js" as Constants

Item {
    width: Constants.SCREEN_WIDTH
    height: Constants.SCREEN_HEIGHT
    property int newsIndex: 0
    property bool customerVisitUsToday: false
    property bool cusBannerShowing: false

    onCustomerVisitUsTodayChanged: {
        if (customerVisitUsToday){
            idWelcomCusTimer.start()
        }
        else
        {
            idWelcomCusTimer.stop()
        }
    }

    Image {
        id: idBackground
        source: "qrc:/Qml/Images/Standby/background.png"
        x: 0
        y: 0
        opacity: 1
    }

    WelcomeCustomerScreen{
        id: idWelcomeCusScreen
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        visible: false
    }

    PhotoPlayer{
        id:idPhotoPlayer
        x: 0
        y: 0
        width: 796
        height: parent.height
        isNextPrevButtonEnabled: false
        Component.onCompleted: {
            console.log("PhotoPlayer Load Complete")
            loadNewsPhoto();
            loadPhotoTimer.start()
        }

        onImagePathChanged: {
            console.log("Image path: " + imagePath)
        }

        onVisibleChanged: {
            if (!visible)
            {
                console.log("idPhotoPlayer Screen Hide")
                loadNewsPhoto()
            }
        }
    }

    PhotoPlayer{
        id:idPhotoPlayerBuffer
        x: 0
        y: 0
        width: 796
        height: parent.height
        isNextPrevButtonEnabled: false
        visible: !idPhotoPlayer.visible

        onVisibleChanged: {
            if (!visible)
            {
                console.log("idPhotoPlayerBuffer Screen Hide")
                loadNewsPhotoBuffer()
            }
        }

        onImagePathChanged: {
            console.log("Image path: " + imagePath)
        }
    }

    Video {
        id: idStandByVideo
        x: idPhotoPlayer.width
        y: 0
        width: parent.width - idPhotoPlayer.width
        height: parent.height
        source: StandbyModel.videoScr
        autoLoad: true
        autoPlay: true
        fillMode: VideoOutput.Stretch
        loops: MediaPlayer.Infinite
    }

    Timer{
        id: loadPhotoTimer
        interval: 4000
        repeat: true
        onTriggered: {
            //Show another photo
            console.log("loadPhotoTimer trigger")
            idPhotoPlayer.visible = idPhotoPlayer.visible ? false : true
        }
    }

    function loadNewsPhoto()
    {
        idPhotoPlayer.imagePath = StandbyModel.newsList[newsIndex]
        newsIndex = newsIndex + 1 === StandbyModel.newsList.length ? 0 : newsIndex + 1
    }

    function loadNewsPhotoBuffer()
    {
        idPhotoPlayerBuffer.imagePath = StandbyModel.newsList[newsIndex]
        newsIndex = newsIndex + 1 === StandbyModel.newsList.length ? 0 : newsIndex + 1
    }

    //TODO Add timer handle show WELCOME CUSTOMER banner

    Timer
    {
        id: idWelcomCusTimer
        interval:  60000
        repeat: true

        onTriggered: {
            cusBannerShowing = !cusBannerShowing
            showWelcomBanner(cusBannerShowing)
        }
    }

    function showWelcomBanner(isShow)
    {
        if (isShow === true){
            idPhotoPlayer.visible = false
            idPhotoPlayerBuffer.visible = false
            idStandByVideo.visible = false
            loadPhotoTimer.stop()

            //Show Banner
            idWelcomeCusScreen.visible = true
            //Start Hide Banner Timer
        }
        else
        {
            //Hide Banner
            idWelcomeCusScreen.visible = false
            //Stop Hide Banner Timer

            idPhotoPlayer.visible = true
            idPhotoPlayerBuffer.visible = true
            idStandByVideo.visible = true
            loadPhotoTimer.start()


        }
    }
}
