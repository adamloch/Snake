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

    bool checkIfLost();

    void keyPressEvent(QKeyEvent *event);
    void checkBorders();
    void checkIfOnApple();
    void getPowerUpPtr(powerUp *ptr);
    void addRect(double posX,double posY);
    void deleteLastRect();
public slots:
    void move();
private:
    double dx;
    double dy;
    double headX;
    double headY;
    double powerUpX;
    double powerUpY;
    powerUp *powerUpPtr;
    std::list<rects*>l;
};
#endif // SNAKE_H
