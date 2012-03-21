#ifndef LEVELITEM_H
#define LEVELITEM_H

#include <QIcon>
#include <QString>

struct LevelItem
{
    LevelItem(int id, QIcon icon, QString name )
    {
        this->id = id;
        this->icon = icon;
        this->name = name;
    }

    int id;
    QIcon icon;
    QString name;
};

#endif // LEVELITEM_H
