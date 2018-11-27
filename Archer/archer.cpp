
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include "archer.h"
#include "arrow.h"

archer::archer()
{
    this->setRect(0,0,10,50);
    this->setPos(0,550);
}

void archer::createArrow()
{
 arrow *arrow1=new arrow(40,40);
 scene()->addItem(arrow1);
 arrow1->setPos(this->x(),this->y());
}
