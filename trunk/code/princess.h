#ifndef PRINCESS_H
#define PRINCESS_H

#include <QObject>
#include "gameobject.h"

class Princess : public GameObject
{
    Q_OBJECT
public:
    explicit Princess(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PRINCESS_H
