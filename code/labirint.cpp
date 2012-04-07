#include "labirint.h"

Labirint::Labirint()
{
    this->height = 0;
    this->width = 0;

    //set map of items,roads and walls

    //set map of actions
}

void Labirint::setObject(int row, int column, GameObject* object)
{
    map.insert(new QPoint(column,row),object);
}

void Labirint::setDimension(int height, int width)
{
    this->height = height;
    this->width = width;    
}
