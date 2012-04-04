// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtQuick 1.0

Rectangle {
    id: rectangle1
    width: 800
    height: 600

    Text {
        id: text1
        x: 263
        y: 52
        width: 275
        height: 40
        color: "#ffe54d"
        text: "Lead Programming"
        smooth: false
        style: "Sunken"
        verticalAlignment: "AlignVCenter"
        horizontalAlignment: "AlignHCenter"
        font.pixelSize: 30
        font.family: "MV Boli"
        opacity: 0
    }

    Text {
        id: text2
        x: 287
        y: 98
        color: "#ffe54d"
        text: qsTr("Yuri Shakalov")
        font.strikeout: false
        font.italic: false
        font.bold: false
        font.underline: false
        style: "Outline"
        font.pixelSize: 36
        font.family: "MV Boli"
        verticalAlignment: "AlignVCenter"
        horizontalAlignment: "AlignHCenter"
        opacity: 0
    }

    Text {
        id: text3
        x: 306
        y: 179
        color: "#ffe54d"
        text: qsTr("Art & Design")
        font.family: "MV Boli"
        font.pixelSize: 30
        style: "Sunken"
        horizontalAlignment: "AlignHCenter"
        verticalAlignment: "AlignVCenter"
        opacity: 0
    }

    Text {
        id: text4
        x: 266
        y: 219
        color: "#ffe54d"
        text: qsTr("Olexandra Koval")
        rotation: 0
        transformOrigin: "Center"
        style: "Outline"
        font.pixelSize: 36
        font.family: "MV Boli"
        verticalAlignment: "AlignVCenter"
        horizontalAlignment: "AlignHCenter"
        opacity: 0
    }

    Text {
        id: text5
        x: 268
        y: 301
        color: "#ffe54d"
        text: qsTr("Level programming")
        style: "Sunken"
        font.pixelSize: 30
        font.family: "MV Boli"
        verticalAlignment: "AlignVCenter"
        horizontalAlignment: "AlignHCenter"
        opacity: 0
    }

    Text {
        id: text6
        x: 189
        y: 341
        color: "#ffe54d"
        text: qsTr("Anton El-Khoury-Khanna")
        style: "Outline"
        font.pixelSize: 36
        font.family: "MV Boli"
        verticalAlignment: "AlignVCenter"
        horizontalAlignment: "AlignHCenter"
        opacity: 0
    }


    Text {
        id: text7
        x: 226
        y: 421
        color: "#ffe54d"
        text: qsTr("Additional Programming")
        style: "Sunken"
        font.pixelSize: 30
        font.family: "MV Boli"
        horizontalAlignment: "AlignHCenter"
        verticalAlignment: "AlignVCenter"
        opacity: 0
    }

    Text {
        id: text8
        x: 279
        y: 461
        color: "#ffe54d"
        text: qsTr("Andriy Manko")
        style: "Outline"
        font.pixelSize: 36
        font.family: "MV Boli"
        verticalAlignment: "AlignVCenter"
        horizontalAlignment: "AlignHCenter"
        opacity: 0
    }

    Image {
        id: image1
        x: 0
        y: 0
        width: 800
        height: 600
        anchors.topMargin: 0
        anchors.fill: parent
        source: "graphics/crow.png"
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
            onClicked: if(rectangle1.state != "About screen")
                       {
                           rectangle1.state = "About screen";
                       }
                       else
                       {
                           rectangle1.state = "base state";
                       }
        }
    }

    states: [
        State {
            name: "About screen"

            PropertyChanges {
                target: image1
                x: 0
                y: 0
                width: 800
                height: 600
                anchors.topMargin: 0
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
                opacity: 0
            }

            PropertyChanges {
                target: text1
                opacity: 1
            }

            PropertyChanges {
                target: text2
                opacity: 1
            }

            PropertyChanges {
                target: text3
                opacity: 1
            }

            PropertyChanges {
                target: text4
                opacity: 1
            }

            PropertyChanges {
                target: text5
                opacity: 1
            }

            PropertyChanges {
                target: text6
                opacity: 1
            }

            PropertyChanges {
                target: text7
                opacity: 1
            }

            PropertyChanges {
                target: text8
                opacity: 1
            }
        }
    ]

    transitions: [
        Transition {
            from: "base state"
            to: "About screen"
            PropertyAnimation { target: image1; property: "opacity"; to: 0.4}
        },

        Transition {
            from: "About screen"
            to: "base state"
            PropertyAnimation { target: image1; property: "opacity"; to: 1.0}
        }

    ]
}
