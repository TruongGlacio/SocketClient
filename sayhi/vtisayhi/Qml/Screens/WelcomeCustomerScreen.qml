import QtQuick 2.0

Item {
    id: idCustomer
    Rectangle {
        id : idCusField
        anchors.fill: parent
        Text {
            id: idCusText
            anchors.centerIn: parent
            text: qsTr("Customer's name")
            font.pixelSize: 40
            color: "Green"
        }
        color: "red"
    }

}
