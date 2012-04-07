#ifndef LABIRINT_H
#define LABIRINT_H

#include <QPoint>
#include <QMap>
#include "gameobject.h"
#include <iostream>

class Labirint
{
public:
    Labirint();
    void setObject(int row, int column,GameObject *object);
    void setDimension(int height, int width);
    int getHeight() { return height; }
    int getWidth() { return width; }

    //for test
        void print(){
             for(int i = 0; i < height; i++)
             {
                  for(int j = 0; j < width; j++){
                      std::cout<< map.value(new QPoint(j,i))->getId() << " r";
                  }
                  std::cout<<std::endl;
             }
        }

private:
    QMap<QPoint*, GameObject*> map;
    int height;
    int width;
};

#endif // LABIRINT_H
