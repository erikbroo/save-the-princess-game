#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QVector>
#include "labirint.h"

class GameEngine : public QObject
{
    Q_OBJECT
public:
    explicit GameEngine(QObject *parent = 0);
    bool loadLevel(QString levelFilename);
    
signals:
    
public slots:

private:
    Labirint labirint;

    //list to identify objects using their id's
    QMap<int,QString> objectsList;

    void initObjectsList();
    QVector<int> extractNumber(QByteArray line);
};

#endif // GAMEENGINE_H
