
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include "archer.h"
#include "arrow.h"

archer::archer():
    Vx{300},Vy{15},t{0.03},g{9.81}
{
}

void archer::createArrow()
{
 arrow *arrow1=new arrow;
 scene()->addItem(arrow1);
 currentArrow=arrow1;
 currentArrow->x=5;
 currentArrow->y=570;
 currentArrow->setPos(currentArrow->x,
                      currentArrow->y);
 this->setRect(0,0,10,50);
 QTimer *timer = new QTimer();
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));

  timer->start(30);
}

void archer::move()
{
    currentArrow->x+=Vx*t;
    currentArrow->y-=Vy-(g*t*t*0.5);
    Vx=Vx;
    Vy=Vy-(g*t);
    currentArrow->setPos(currentArrow->x,currentArrow->y);

}
