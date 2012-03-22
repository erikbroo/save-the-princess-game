#ifndef HOLER_H
#define HOLER_H

#include <QObject>
#include "gameobject.h"

class Holer : public GameObject
{
    Q_OBJECT
public:
    explicit Holer(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // HOLER_H
