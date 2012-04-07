#ifndef LABIRINT_H
#define LABIRINT_H

#include <QPoint>
#include <QVector>
#include "gameobject.h"
#include <iostream>

struct MapItem
{
    int row;
    int column;
    GameObject* object;
    MapItem(int x, int y, GameObject* o) :
        row(y), column(x), object(o){}
};

class Labirint
{
public:
    Labirint();
    void setObject(int row, int column,GameObject *object);
    void setDimension(int height, int width);
    int getHeight() { return height; }
    int getWidth() { return width; }
    GameObject* getItemFromPosition(int row, int column);

    //for test
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

private:
    QVector<MapItem*> map;
    int height;
    int width;
};

#endif // LABIRINT_H
