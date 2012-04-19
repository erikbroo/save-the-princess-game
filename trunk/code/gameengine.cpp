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

                labyrinth.setObject(i,j,chooseItemById(id));
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
