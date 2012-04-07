#ifndef WATER_H
#define WATER_H

#include "gameobject.h"

class Water : public GameObject
{
public:
    Water(int id, QString name);
    void performAction();
};

#endif // WATER_H
