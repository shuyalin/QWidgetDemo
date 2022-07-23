import QtQuick 2.0
import QtQuick.Controls 2.2
Rectangle{
    id:root
    property var itemColor:"#000000"
    property var showText:""
    color:itemColor

    signal click(var objectName)
    Text {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        text: showText
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            click(objectName)
        }
    }
}
