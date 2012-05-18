// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: level_block
    width: 50
    height: 50
    color: "transparent"
    x: 0
    y: 0
    property int type: 0

    Image
    {
        id: img
        anchors.fill: parent

        source: {
            if(type == 0){
                "graphics/grass.gif";
            } else if(type == 1) {
                "graphics/bush.gif";
            } else if(type == 2) {
                "graphics/hero.gif";
            } else {
                ""
            }
        }

    }
}
