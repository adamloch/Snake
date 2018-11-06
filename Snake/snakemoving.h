#ifndef SNAKEMOVING_H
#define SNAKEMOVING_H
#include <vector>
#include <iostream>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
class snakeMoving
{

public:
    friend class SnakeHead;
    friend class apple;
    SnakeHead *head;
    QGraphicsScene *ptr_scene;
    double applex;
    double appley;
    snakeMoving( QGraphicsScene *scene)
    {
       ptr_scene=scene;
    }

    void getHeadPtr(SnakeHead *head_ptr);
    void getApplePos(double x,double y);
    void push_back();

};

#endif // SNAKEMOVING_H
