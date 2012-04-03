// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtQuick 1.0

Rectangle {
    id: rectangle1
    width: 800
    height: 600

    Image {
        id: image1
        anchors.fill: parent
        source: "graphics/crow.png"

        Text {
            id: text1
            x: 246
            y: 146
            text: qsTr("text")
            font.pixelSize: 12
            opacity: 0
        }
    }

    Text {
        id: play
        color: "#f7eca4"
        text: qsTr("Play")
        anchors.right: parent.right
        anchors.rightMargin: 352
        anchors.left: parent.left
        anchors.leftMargin: 342
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 327
        anchors.top: parent.top
        anchors.topMargin: 234
        font.bold: true
        style: Text.Sunken
        font.family: "MV Boli"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 35

        MouseArea {
            id: mouse_area_play
            hoverEnabled: true
            anchors.fill: parent

            onHoveredChanged: if(mouse_area_play.containsMouse)
                              {
                                  play.style = Text.Raised;
                              }
                              else
                              {
                                  play.style = Text.Sunken;
                              }
        }
    }

    Text {
        id: close
        color: "#f56c58"
        text: qsTr("x")
        anchors.right: parent.right
        anchors.rightMargin: 16
        anchors.left: parent.left
        anchors.leftMargin: 743
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 534
        anchors.top: parent.top
        anchors.topMargin: 11
        styleColor: "#000000"
        font.bold: true
        style: Text.Sunken
        font.family: "MV Boli"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 73

        MouseArea {
            id: mouse_area_close
            hoverEnabled: true
            anchors.fill: parent

            onHoveredChanged: if(mouse_area_close.containsMouse)
                              {
                                  close.style = Text.Raised;
                              }
                              else
                              {
                                  close.style = Text.Sunken;
                              }


            onClicked: Qt.quit();
        }
    }

    Text {
        id: about
        color: "#00c5ff"
        text: qsTr("?")
        anchors.right: parent.right
        anchors.rightMargin: 16
        anchors.left: parent.left
        anchors.leftMargin: 743
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 23
        anchors.top: parent.top
        anchors.topMargin: 522
        font.pixelSize: 73
        style: Text.Sunken
        font.family: "MV Boli"
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        MouseArea {
            id: mouse_area_about
            hoverEnabled: true
            anchors.fill: parent

            onHoveredChanged: if(mouse_area_about.containsMouse)
                              {
                                  about.style = Text.Raised;
                              }
                              else
                              {
                                  about.style = Text.Sunken;
                              }
        }
    }
    states: [
        State {
            name: "About screen"

            PropertyChanges {
                target: image1
                smooth: true
                clip: false
                opacity: 0.400
            }

            PropertyChanges {
                target: mouse_area_close
                enabled: true
            }

            PropertyChanges {
                target: mouse_area_play
                opacity: 1
                enabled: false
            }

            PropertyChanges {
                target: mouse_area_about
                enabled: true
            }

            PropertyChanges {
                target: play
                text: "Play"
                opacity: 0.400
            }

            PropertyChanges {
                target: text1
                width: 288
                height: 38
                text: "text"
                opacity: 1
            }
        }
    ]
}
