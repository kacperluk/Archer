#include "enemy.h"
#include <QGraphicsScene>
#include <cstdlib>
enemy::enemy()
{
    drawEnemyAtRandPos();
}
void enemy::drawEnemyAtRandPos()
{


    //random position on the scene
    int x=rand()%800;
    int y=rand()%600;
    setPos(x,y);
    setRect(0,0,20,50);
}

double enemy::getEnemyX()
{
    return this->x();
}
double enemy::getEnemyY()
{
    return this->y();
}

