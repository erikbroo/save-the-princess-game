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

    void setObject(int row, int column, GameObject *object);
    void setDimension(int height, int width);
    int getHeight() { return height; }
    int getWidth() { return width; }
    GameObject* getItemFromPosition(int row, int column);

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
    int height;
    int width;
};

#endif // LABIRINT_H
