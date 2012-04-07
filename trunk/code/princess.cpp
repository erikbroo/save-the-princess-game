#include "princess.h"

Princess::Princess(QObject *parent) :
    GameObject(parent)
{
}

Princess::Princess(int id, QString name) :
    GameObject(id ,name)
{
}

void Princess::performAction()
{
}
