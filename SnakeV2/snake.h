#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <list>
class snake:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
    friend class rects;
    friend class powerUp;
public:
    snake();
    double dx;
    double dy;
    powerUp *powerUpPtr;
    void keyPressEvent(QKeyEvent *event);
    void checkPos();
    void getPowerUpPtr(powerUp *ptr);

    std::list<rects*>l;
    void addRect(double posX,double posY);
    void deleteLastRect();
public slots:
    void move();

};
#endif // SNAKE_H
