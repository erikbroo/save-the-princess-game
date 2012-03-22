#ifndef FOE_H
#define FOE_H

#include <QObject>
#include "gameobject.h"

class Foe : public GameObject
{
    Q_OBJECT
public:
    explicit Foe(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // FOE_H
