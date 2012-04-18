#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QMap>
#include <QVector>
#include "labyrinth.h"
#include "grasswall.h"
#include "foe.h"
#include "player.h"
#include "princess.h"

class GameEngine : public QObject
{
    Q_OBJECT
public:
    explicit GameEngine(QObject *parent = 0);
    
signals:
    
public slots:
    void startEngine();
    void stopEngine();

private:
    Labyrinth labyrinth;

    //list to identify objects using their id's
    QMap<int,QString> objectsList;

    void            initObjectsList();
    QVector<int>    extractNumber(QByteArray line);
    GameObject*     chooseItemById(int id);
    bool            loadLevel(QString levelFilename);
};

#endif // GAMEENGINE_H
