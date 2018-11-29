#include "archer.h"
#include "arrow.h"

archer::archer()
{
    this->setRect(0,0,10,50);
    this->setPos(0,550);
}
void archer::createArrow(int V0x,int V0y)
{
 arrow *arrow1=new arrow(V0x,V0y);
 scene()->addItem(arrow1);
 arrow1->setPos(this->x(),this->y());
}
