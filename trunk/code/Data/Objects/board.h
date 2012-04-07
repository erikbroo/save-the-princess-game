#ifndef BOARD_H
#define BOARD_H

#include "gameobject.h"

class Board : public GameObject
{
public:
    Board(int id, QString name);
    void performAction();
};

#endif // BOARD_H
