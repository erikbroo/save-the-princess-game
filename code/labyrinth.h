#ifndef LABIRINT_H
#define LABIRINT_H

#include <QPoint>
#include <QObject>
#include <QVector>
#include <QVariant>
#include "gameobject.h"
#include <iostream>

struct MapItem
{
    int row;
    int column;
    GameObject* object;
    MapItem(int x, int y, GameObject* o) :
        row(y), column(x), object(o){}
    ~MapItem()
    {
        delete object;
    }
};

class Labyrinth
{
public:
    Labyrinth();
    ~Labyrinth();

    void setItem(int row, int column, GameObject *object);
    GameObject* getItem(int row, int column);
    void setDimension(int height, int width);
    int getHeight() { return height; }
    int getWidth() { return width; }

    QVariantList convertToQVariantForm();

#ifdef PRINT_TEST
        void print(){
             for(int i = 0; i < height; i++)
             {
                  for(int j = 0; j < width; j++){
                      GameObject* id = getItemFromPosition(i,j);
                      if (id) std::cout<<  id->getId() << " ";
                      else std::cout<< "0 ";
                  }
                  std::cout<<std::endl;
             }
        }
#endif

private:
    QVector<MapItem*> map;
    GameObject*** labyrinth;
    int height;
    int width;
};

#endif // LABIRINT_H
