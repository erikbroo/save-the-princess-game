#include "labirint.h"

Labirint::Labirint()
{
    this->height = 0;
    this->width = 0;
}

void Labirint::setObject(int row, int column, GameObject* object)
{
    map.append(new MapItem(column,row,object));
}

void Labirint::setDimension(int height, int width)
{
    this->height = height;
    this->width = width;
}

GameObject *Labirint::getItemFromPosition(int row, int column)
{
    foreach(MapItem* item, map)
    {
        if (item->row == row && item->column == column)
        {
            return item->object;
        }
    }

    return 0;
}
