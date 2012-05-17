#include "labyrinth.h"

Labyrinth::Labyrinth()
{
    this->height = 0;
    this->width = 0;
    this->labyrinth = 0;
}

Labyrinth::~Labyrinth()
{
    if(this->height != 0 && this->width != 0)
    {
        for(int i = 0; i < this->height; ++i)
        {
            for(int j = 0; j < this->width; ++j)
            {
                delete labyrinth[i][j];
            }

            delete labyrinth[i];
        }

        delete labyrinth;
    }
}

void Labyrinth::setItem(int row, int column, GameObject* object)
{
    labyrinth[row][column] = object;
}

void Labyrinth::setDimension(int height, int width)
{
    if(this->height != 0 && this->width != 0) //if resizing an already used labyrinth
    {
        for(int i = 0; i < this->height; ++i)
        {
            for(int j = 0; j < this->width; ++j)
            {
                delete labyrinth[i][j];
            }

            delete labyrinth[i];
        }

        delete labyrinth;
    }

    this->height = height;
    this->width = width;

    labyrinth = new GameObject**[height];

    for(int i = 0; i < height; ++i)
    {
        labyrinth[i] = new GameObject*[width];

        for(int j = 0; j < width; ++j)
        {
            labyrinth[i][j] = 0;
        }
    }
}

GameObject *Labyrinth::getItem(int row, int column)
{
    return labyrinth[row][column];
}

QVariantList Labyrinth::convertToQVariantForm()
{
    QVariantList result;

    for(int i = 0; i < this->getHeight(); ++i)
    {
        for(int j = 0; j < this->getWidth(); ++j)
        {
            GameObject* obj = this->getItem(i,j);

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
