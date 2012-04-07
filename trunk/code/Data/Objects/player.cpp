#include "player.h"

Player::Player(QObject *parent) :
    GameObject(parent)
{
}

Player::Player(int id, QString name) :
    GameObject(id, name)
{
}

void Player::performAction()
{
}
