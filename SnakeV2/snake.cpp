#include "snake.h"
#include "rects.h"
#include "powerUp.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <list>
#include <QTimer>
#include <iterator>

#include <iostream>
snake::snake()
{
  //  rects *newRect=new rects(30,30);
    // l.push_front(newRect);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void snake::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        dy=-20;
        dx=0;
        break;
    case Qt::Key_Down:
        dy=20;
        dx=0;
        break;
    case Qt::Key_Left:
        dy=0;
        dx=-20;
        break;
    case Qt::Key_Right:
        dy=0;
        dx=20;
        break;
    }
}

void snake::checkPos()
{
    double headX=l.front()->pos().x();
    double headY=l.front()->pos().y();
    double powerUpX=powerUpPtr->powerUpX;
    double powerUpY=powerUpPtr->powerUpY;
    if     (headY>580)  {l.front()->setPos(headX,0);}
    else if(headY<0)    {l.front()->setPos(headX,580);}
    else if(headX>780)  {l.front()->setPos(0    ,headY);}
    else if(headX<0)    {l.front()->setPos(780  ,headY);};

    if(headX==powerUpX&&headY==powerUpY)
    {
    scene()->removeItem(powerUpPtr);
    delete powerUpPtr;
    powerUpPtr=new powerUp;
    scene()->addItem(powerUpPtr);
    }
    else
        deleteLastRect();

    std::list <rects*> :: iterator it;
    it =l.begin();
    it++;
    bool lose=false;
    for(;it!=l.end();it++)
    {

        if( headX==(*it)->rectsX &&headY==(*it)->rectsY)
        lose=true;
    }
    it =l.begin();
    if(lose==true)
    {
        for(;it!=l.end();it++)
        {
            scene()->removeItem(*it);

        }
        l.clear();
        addRect(380,280);

    }
}

void snake::getPowerUpPtr(powerUp *ptr)
{
    powerUpPtr=ptr;
}

void snake::deleteLastRect()
{
  scene()->removeItem(l.back());
  l.pop_back();
}

void snake::move()
{
    addRect(l.front()->x()+dx,l.front()->y()+dy);
    checkPos();
}
void snake::addRect(double posX,double posY)
{
    rects *newRect=new rects();
    l.push_front(newRect);
    newRect->setPos(posX,posY);
    newRect->rectsX=posX;
    newRect->rectsY=posY;
    scene()->addItem(newRect);
}
