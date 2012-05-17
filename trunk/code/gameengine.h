#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QMap>
#include <QVariant>
#include <QFile>
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
    void render(QVariantList lab);
    void levelFinished();
    void levelFailed();
    
public slots:
    void startEngine();
    void stopEngine();
    void keyPressed(int key);


private:
    Labyrinth labyrinth;

    //list to identify objects using their id's
    QMap<int,QString> objectsList;

    void            initObjectsList();
    QVector<int>    extractNumber(QByteArray line);
    GameObject*     chooseItemById(int id);
    bool            loadLevel(QString levelFilename);
    bool            validateMove(int old_x, int old_y, int new_x, int new_y);
};

#endif // GAMEENGINE_H
