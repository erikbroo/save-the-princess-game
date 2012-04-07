#include "grasswall.h"

GrassWall::GrassWall(QObject *parent) :
    GameObject(parent)
{
}

GrassWall::GrassWall(int id, QString name) :
    GameObject(id, name)
{

}

void GrassWall::performAction()
{
}

