#include "apple.h"
#include <QGraphicsScene>
apple::apple()
{
    srand( time( NULL ) );
    setRect((std::rand()%40)*20,(std::rand()%30)*20,20,20);
}
