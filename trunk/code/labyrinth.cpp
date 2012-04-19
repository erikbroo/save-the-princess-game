#include "labyrinth.h"

Labyrinth::Labyrinth()
{
    this->height = 0;
    this->width = 0;
}

Labyrinth::~Labyrinth()
{
    int len = map.size();

    for(int i = 0; i < len; ++i)
    {
        MapItem* item = map[0];

        delete item;

        map.remove(0);
    }
}

void Labyrinth::setObject(int row, int column, GameObject* object)
{
    map.append(new MapItem(column,row,object));
}

void Labyrinth::setDimension(int height, int width)
{
    this->height = height;
    this->width = width;
}

GameObject *Labyrinth::getItemFromPosition(int row, int column)
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

QVariantList Labyrinth::convertToQVariantForm()
{
    QVariantList result;

    for(int i = 0; i < this->getHeight(); ++i)
    {
        for(int j = 0; j < this->getWidth(); ++j)
        {
            GameObject* obj = this->getItemFromPosition(i,j);

            if(obj)
            {
                result.append(obj->getId());
            }
            else
            {
                result.append(0);
            }
        }
    }

    return result;
}
