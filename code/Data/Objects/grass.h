#ifndef GRASS_H
#define GRASS_H

#include "gameobject.h"

class Grass : public GameObject
{
public:
    Grass(int id, QString name);
    void performAction();
};

#endif // GRASS_H
