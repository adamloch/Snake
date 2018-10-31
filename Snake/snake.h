#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsRectItem>
#include <QObject>

class Snake:public QObject,public QGraphicsRectItem
{
     Q_OBJECT
public:

    void check_position();
    Snake();

    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
};

#endif // SNAKE_H
