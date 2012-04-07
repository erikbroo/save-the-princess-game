#ifndef GRASSWALL_H
#define GRASSWALL_H

#include <QObject>
#include "gameobject.h"

class GrassWall : public GameObject
{
    Q_OBJECT
public:
    explicit GrassWall(QObject *parent = 0);
    GrassWall(int id, QString name);

    void performAction();
    
};

#endif // GRASSWALL_H
