#include "powerUp.h"
powerUp::powerUp()
{
    srand(time(NULL));
    powerUpX=((std::rand()%40)*20);
    powerUpY=((std::rand()%30)*20);
    setRect(powerUpX,powerUpY,20,20);
}
