#ifndef LABIRINT_H
#define LABIRINT_H

#include <QPoint>
#include <QMap>
#include <iostream>

class Labirint
{
public:
    Labirint();
    void setObject(int row, int column,int id);
    void setDimension(int height, int width);
    int getHeight() { return height; }
    int getWidth() { return width; }

    //for test
    void print(){
         for(int i = 0; i < height; i++)
         {
              for(int j = 0; j < width; j++){
                  std::cout<< map[i][j] << "";
              }
              std::cout<<std::endl;
         }
    }

private:
    int** map;
    int height;
    int width;
};

#endif // LABIRINT_H
