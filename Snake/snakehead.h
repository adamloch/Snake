#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsRectItem>
#include <QObject>


class SnakeHead:public QObject,public QGraphicsRectItem
{
 Q_OBJECT
    friend class apple;
    friend class tail;
private:
    double dx;
    double dy;
    tail *first_tail;
    apple *powerup;
    QGraphicsScene *scene_ptr;
public:
    void check_head_pos();
    void change_head_direction(double newdx,double newdy);
    void getApplePtr(apple *ptr);
    SnakeHead();
   void keyPressEvent(QKeyEvent *event);
public slots:
    void move();

};


#endif // SNAKE_H
