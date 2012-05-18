// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import Engine 1.0

Rectangle {
    id: field
    width: 800
    height: 600
    color: "#000000"
    focus: true

    signal closeMe

    GameEngine
    {
        id: engine
        property bool started: false

        onRender:
        {
            console.log("Render signal captured");

            var component = Qt.createComponent("level_block.qml");

            for(var j = 0; j < 12; ++j)
            {
                for(var i = 0; i < 16; ++i)
                {
                    if(component.status == Component.Ready)
                    {
                        var obj = component.createObject(field);

                        if(obj == null)
                        {
                            console.log("Error creating block");

                            return;
                        }

                        obj.x = i*50;
                        obj.y = j*50;
                        obj.width = 50;
                        obj.height = 50;

                        if(lab[j*16+i] == 0)
                        {
                            obj.type = 0;
                        }
                        else if(lab[j*16+i] == 1)
                        {
                            obj.type = 1;
                        }
                        else if(lab[j*16+i] == 2)
                        {
                            obj.type = 2;
                        }
                        else if(lab[j*16+i] == 3)
                        {
                            obj.type = 3;
                            obj.color = "pink";
                        }
                        else if(lab[j*16+i] == 4)
                        {
                            obj.type = 4;
                            obj.color = "black";
                        }
                        else
                        {
                            obj.type = -1;
                            obj.color = "yellow";
                        }

                    }
                    else
                    {
                        console.log("Error loading block component");

                        return;
                    }
                }
            }
        }

        onLevelFinished:
        {
            console.log("Close signal captured");
            field.closeMe();
        }

        onLevelFailed:
        {
            console.log("Close signal captured");
            field.closeMe();
        }
    }

    Keys.onPressed:
    {
        engine.keyPressed(event.key);
        //event.accepted = true; //if uncomment, key pressed events won't be processed by main.qml from render.qml is launched
    }

    onActiveFocusChanged:
    {
        if(field.activeFocus == true)
        {
            if(!engine.started)
            {
                engine.startEngine();
                engine.started = true;
            }
        }
        else
        {
            if(engine.started)
            {
                engine.stopEngine();
                engine.started = false;
            }
        }
    }
}
