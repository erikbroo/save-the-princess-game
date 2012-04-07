#ifndef STONEWALL_H
#define STONEWALL_H

#include "gameobject.h"

class StoneWall : public GameObject
{
public:
    StoneWall(int id, QString name);
    void performAction();
};

#endif // STONEWALL_H
