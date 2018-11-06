#ifndef TAIL_H
#define TAIL_H
#include <QGraphicsRectItem>
#include <QObject>


class tail:public QObject,public QGraphicsRectItem
{

public:
    tail *next;
    tail(){
        next=nullptr;
        setRect(0,0,30,20);
        }

};

#endif // TAIL_H
