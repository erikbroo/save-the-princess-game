#ifndef FOE_H
#define FOE_H

#include <QObject>
#include "gameobject.h"

class Foe : public GameObject
{
    Q_OBJECT
public:
    explicit Foe(QObject *parent = 0);
    Foe(int id, QString name);
    void performAction();
    
signals:
    
public slots:
    
};

#endif // FOE_H
