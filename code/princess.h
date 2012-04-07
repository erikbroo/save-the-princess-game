#ifndef PRINCESS_H
#define PRINCESS_H

#include <QObject>
#include "gameobject.h"

class Princess : public GameObject
{
    Q_OBJECT
public:
    explicit Princess(QObject *parent = 0);
    Princess(int id, QString name);
    void performAction();
    
signals:
    
public slots:
    
};

#endif // PRINCESS_H
