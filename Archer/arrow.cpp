#include "arrow.h"
#include <math.h>
#include <QGraphicsScene>
arrow::arrow(double vx,double vy):
    Vx{vx},Vy{vy},nextPosX{0},nextPosY{0},rotAngle{0},t{0.01},
    g{9.81},
    pi{3.141592}
{
    drawArrow();
    setTimerForMove(t*300);
}
void arrow::drawArrow()
{
    this->setPos(nextPosX,nextPosY);
    this->setRotation(rotAngle);
    this->setRect(0,0,40,1);
}
void arrow::hideArrow()
{
    this->setRect(0,0,0,0);
}
void arrow::setTimerForMove(int ms)
{
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(ms);
}
void arrow::calculateNextPosValues()
{
    //position
    nextPosX=this->x()+Vx*t;
    nextPosY=this->y()-(Vy*t-(g*t*t*0.5));
    //velocity
    Vy=Vy-(g*t);
    Vx=Vx;
    //rotation
    rotAngle=(atan(Vx/Vy)*180/pi);
    if(rotAngle>0)
        rotAngle-=90;
    else
        rotAngle+=90;

}

void arrow::checkSceneBorders()
{
    if(x()>scene()->width()||x()<0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    if(y()>scene()->height()||y()<0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
void arrow::move()
{
    hideArrow();
    calculateNextPosValues();
    drawArrow();
    checkSceneBorders();
}
