#include "foe.h"

Foe::Foe(QObject *parent) :
    GameObject(parent)
{
}

Foe::Foe(int id, QString name) :
    GameObject(id, name)
{
}

void Foe::performAction()
{
}
