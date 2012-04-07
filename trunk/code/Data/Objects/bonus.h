#ifndef BONUS_H
#define BONUS_H

#include <QObject>
#include "gameobject.h"

class Bonus : public GameObject
{
    Q_OBJECT
public:
    explicit Bonus(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // BONUS_H
