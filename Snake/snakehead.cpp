#include "snakehead.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include "apple.h"
#include "tail.h"
void SnakeHead::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        this->change_head_direction(0,-20);
        break;
    case Qt::Key_Down:
        this->change_head_direction(0,20);
        break;
    case Qt::Key_Left:
        this->change_head_direction(-20,0);
        break;
    case Qt::Key_Right:
        this->change_head_direction(20,0);
        break;
    }
}
void SnakeHead::change_head_direction(double newdx,double newdy)
{
    dx = newdx;
    dy = newdy;
}

void SnakeHead::getApplePtr(apple *ptr)
{
    powerup=ptr;
}

void SnakeHead::move()
{
    check_head_pos();

   setPos(x()+this->dx,y()+this->dy);

}
void SnakeHead::check_head_pos()
{
    if     (pos().y()>580)  {setPos(pos().x(),0 );}
    else if(pos().y()<0)    {setPos(pos().x(),580);}
    else if(pos().x()>780)  {setPos(0        ,pos().y());}
    else if(pos().x()<0)    {setPos(780      ,pos().y());};
    if(pos().y()==powerup->appleY&&pos().x()==powerup->appleX)//sprawdzam pole podemna
    {
       scene()->removeItem(powerup);
       delete powerup;
       powerup=nullptr;
       powerup=new apple;
       scene()->addItem(powerup);

       if(first_tail==nullptr)
       {
           first_tail=new tail;
           first_tail->setPos(x(),y());
           scene()->addItem(first_tail);
     }
       else
       {
           tail *cpy_first_tail=new tail;
           cpy_first_tail=first_tail;
           tail *new_tail=new tail;
           scene()->addItem(new_tail);
           new_tail->setPos(x(),y());
           first_tail=new_tail;
           first_tail->next=cpy_first_tail;
       }

    }
  /*  else
    {
        tail *ptr=first_tail;
        if(ptr!=nullptr)
        {
            while(ptr->next!=nullptr)
                ptr->next;
            scene()->removeItem(ptr);
            delete ptr;
            ptr=nullptr;

        }*/

   // }
}
SnakeHead::SnakeHead()
{
    scene_ptr=nullptr;

    first_tail=nullptr;
    setRect(0,0,20,20);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    powerup=nullptr;

}

