#include "snake.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
void Snake::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        setPos(x(),y()-20);
        check_position();
        break;
    case Qt::Key_Down:
        setPos(x(),y()+20);
        check_position();
        break;
    case Qt::Key_Left:/*
        setPos();
        check_position();*/
        move();
        break;
    case Qt::Key_Right:
       setPos(x()+20,y());
        check_position();
        break;
    }
}
void Snake::move()
{
   setPos(x()-20,y());
    check_position();
}
void Snake::check_position()
{
    if     (pos().y()>580)  {setPos(pos().x(),0 );}
    else if(pos().y()<0)    {setPos(pos().x(),580);}
    else if(pos().x()>780)  {setPos(0        ,pos().y());}
    else if(pos().x()<0)    {setPos(780      ,pos().y());};
}
Snake::Snake()
{
    setRect(0,0,20,20);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}
