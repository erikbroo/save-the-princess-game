#ifndef WALL_H
#define WALL_H

#include <QObject>
#include "gameobject.h"

class Wall : public GameObject
{
    Q_OBJECT
public:
    explicit Wall(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // WALL_H
