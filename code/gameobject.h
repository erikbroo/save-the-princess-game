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
    int getX() { return x; }
    int getY() { return y; }
    void setCoords(int _x, int _y) { x = _x; y = _y; }
    virtual void performAction() = 0;
    
signals:
    
public slots:

private:
    int objectId;
    int x;
    int y;
    QString objectName;
    
};

#endif // GAMEOBJECT_H
