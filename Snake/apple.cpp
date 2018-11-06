#include "apple.h"
#include <QGraphicsScene>


apple::apple()
{
    srand( time( NULL ) );
    appleX=((std::rand()%40)*20);
    appleY=((std::rand()%30)*20);
    setRect(appleX,appleY,20,20);
}
