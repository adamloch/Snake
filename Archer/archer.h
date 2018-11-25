#ifndef ARCHER_H
#define ARCHER_H
#include <QGraphicsRectItem>
#include <QObject>
class archer:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
    friend class arrow;
public:
    double Vx;
    double Vy;
    double t;
    double g;
    arrow *currentArrow;
    archer();

    void createArrow();
public slots:
    void move();
};

#endif // ARCHER_H
