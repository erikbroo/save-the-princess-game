#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "gameobject.h"

class Player : public GameObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    Player(int id, QString name);

    void performAction();
    
signals:
    
public slots:
    
};

#endif // PLAYER_H
