#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>

class GameObject : public QObject
{
    Q_OBJECT
public:
    explicit GameObject(QObject *parent = 0);
    GameObject(int id, QString name) : objectId(id), objectName(name){}

    int getId() { return objectId; }
    virtual void performAction() = 0;
    
signals:
    
public slots:

private:
    int objectId;
    QString objectName;
    
};

#endif // GAMEOBJECT_H
