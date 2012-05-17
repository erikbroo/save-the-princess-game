#include "gameengine.h"

GameEngine::GameEngine(QObject *parent) :
    QObject(parent)
{
    initObjectsList();
}

bool GameEngine::loadLevel(QString levelFilename)
{
    QFile level(levelFilename);

    if (!level.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    QByteArray buffer;
    QVector<int> numberVector;

    //read dimension
    if(!level.atEnd())
    {
        buffer = level.readLine();
        numberVector = extractNumber(buffer);
        labyrinth.setDimension(numberVector.at(0),numberVector.at(1));

    } else {
        return false;
    }

    //read items in rows
    for(int i = 0; i < labyrinth.getHeight(); i++)
    {
        numberVector.clear();
        if (!level.atEnd())
        {
            buffer = level.readLine();
            numberVector = extractNumber(buffer);

            //add items to list
            for(int j = 0; j < numberVector.size(); j++)
            {
                int id = numberVector.at(j);
                GameObject* item = chooseItemById(id);

                if(item != 0)
                {
                    item->setCoords(i,j);
                }

                labyrinth.setItem(i,j,item);

                if(id == 2)
                {
                    player = item;
                }
            }
        }
    }
#ifdef PRINT_TEST
    //don't uncomment while map is initiated without objects
    //all values are null
    labirint.print();
#endif
    return true;
}

bool GameEngine::makeMove(int old_x, int old_y, int new_x, int new_y)
{
    if(new_x >= labyrinth.getHeight() || new_y >= labyrinth.getWidth() || new_x < 0 || new_y < 0)
    {
        return false;
    }

    GameObject* character = labyrinth.getItem(old_x,old_y);
    GameObject* next_tile = labyrinth.getItem(new_x,new_y);

    if(next_tile == 0)
    {
        character->setCoords(new_x,new_y);
        labyrinth.setItem(new_x,new_y,character);
        labyrinth.setItem(old_x,old_y,0);
        return true;
    }
    else
    {
        switch(next_tile->getId())
        {
        case 1: //
            return false;
        case 2:
            character->setCoords(new_x,new_y);
            labyrinth.setItem(new_x,new_y,character);
            emit levelFailed();
            return true;
        case 3:
            character->setCoords(new_x,new_y);
            labyrinth.setItem(old_x,old_y,0);
            labyrinth.setItem(new_x,new_y,character);
            emit levelFinished();
            return true;
        case 4:
            labyrinth.setItem(old_x,old_y,0);
            emit levelFailed();
            return true;
        default:
            break;
        }

        return false;
    }
}

void GameEngine::initObjectsList()
{
    int i = 0;

    objectsList.insert(i++,"Grass");
    objectsList.insert(i++,"Grass wall");
    objectsList.insert(i++,"Hero");
    objectsList.insert(i++,"Princess");
    objectsList.insert(i++,"Enemy1");
}

QVector<int> GameEngine::extractNumber(QByteArray line)
{
    QString number = "";
    QVector<int> numbers;
    int i = 0;
    while (i < line.size()) {

        if (QChar(line.at(i)).isDigit()) //find digit
        {
            while (i < line.size() && QChar(line.at(i)).isDigit()){
                number.append(QChar(line.at(i)));
                i++;
            }
            numbers.append(number.toInt());
            number = "";
        } else {
           i++;
        }
    }
    return numbers;
}

GameObject *GameEngine::chooseItemById(int id)
{
    GameObject* object = 0;

    switch (id)
    {
        //case 0 : { object = new Grass(id,"Grass"); break; }
        case 1 : { object = new GrassWall(id,"GrassWall"); break; }
        case 2 : { object = new Player(id,"Hero"); break;}
        case 3 : { object = new Princess(id,"Princess"); break;}
        case 4 : { object = new Foe(id,"Enemy1"); break;}
    }

    return (object);
}

void GameEngine::startEngine()
{
    qDebug("Engine started");

    if(loadLevel("data/level01.spg"))
    {
        qDebug("Level loaded");
        emit render(labyrinth.convertToQVariantForm());
    }
    else
    {
        qDebug("Level loading failed");
    }
}

void GameEngine::stopEngine()
{
    qDebug("Engine stopped");
}

void GameEngine::keyPressed(int key)
{
    qDebug(QString("%1").arg(key,0,16,0).toAscii());

    int x = player->getX();
    int y = player->getY();

    switch(key)
    {
        case Qt::Key_Up:
            makeMove(x,y,x-1,y);
            break;
        case Qt::Key_Down:
            makeMove(x,y,x+1,y);
            break;
        case Qt::Key_Left:
            makeMove(x,y,x,y-1);
            break;
        case Qt::Key_Right:
            makeMove(x,y,x,y+1);
            break;
    }

    emit render(labyrinth.convertToQVariantForm());
}
