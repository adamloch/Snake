#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsRectItem>


class arrow:public QGraphicsRectItem
{
     friend class archer;
public:
    arrow();
    double x;
    double y;

};

#endif // ARROW_H
