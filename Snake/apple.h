#ifndef APPLE_H
#define APPLE_H
#include <QGraphicsRectItem>
class apple:public QGraphicsRectItem
{
     friend class SnakeHead;
public:
    double appleX;
    double appleY;
    double getAppleX();
    double getAppleY();
    apple();
};

#endif // APPLE_H
