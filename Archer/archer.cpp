#include "archer.h"
#include "arrow.h"

archer::archer()
{
    drawThis();
    this->setPos(0,550);
}

void archer::drawThis()
{
    this->setRect(0,0,10,50);
}

void archer::hideThis()
{
    this->setRect(0,0,0,0);
}
