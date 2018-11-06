#include "snakemoving.h"
#include "snakehead.h"
#include <QKeyEvent>
#include <QTimer>
void snakeMoving::getHeadPtr(SnakeHead *head_ptr)
{
    head=head_ptr;
}

void snakeMoving::getApplePos(double x,double y)
{
    applex=x;
    appley=y;
}

void snakeMoving::push_back()
{
   SnakeHead *temp=head;
   SnakeHead *new_head=new SnakeHead;
   while(temp->first_tail!=nullptr)
   {
       temp=temp->first_tail;
   }
   new_head=temp->first_tail;
   ptr_scene->addItem(new_head);
}


