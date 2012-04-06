#include "labirint.h"

Labirint::Labirint()
{
    this->height = 0;
    this->width = 0;

    //set map of items,roads and walls

    //set map of actions
}

void Labirint::setObject(int row, int column, int id)
{
    map[row][column] = id;
}

void Labirint::setDimension(int height, int width)
{
    this->height = height;
    this->width = width;

    //init map
    map = new int*[height];
    for(int i = 0; i < height; i++) {
        map[i] = new int[width];
    }
}
