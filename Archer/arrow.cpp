#include "arrow.h"
#include <QTimer>
#include <math.h>
arrow::arrow(double vx,double vy):
    Vx{vx},Vy{vy},nextPosX{0},nextPosY{0},t{0.01},
    g{9.81},
    pi{3.141592}
{
    drawArrow();
    startMoving(t*300);
}
void arrow::drawArrow()
{
    this->setRect(0,0,40,1);
}
void arrow::hideArrow()
{
    this->setRect(0,0,0,0);
}
void arrow::startMoving(int ms)
{
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(ms);
}
void arrow::rotateArrow()
{
    double rotAngle=(atan(Vx/Vy)*180/pi);
    if(rotAngle>0)
        this->setRotation(rotAngle-90);
    else
        this->setRotation(rotAngle+90);
}
void arrow::calculateNextPosValues()
{
    Vx=Vx;
    nextPosX=this->x()+Vx*t;
    nextPosY=this->y()-(Vy*t-(g*t*t*0.5));
    Vy=Vy-(g*t);
}
void arrow::move()
{
    hideArrow();
    calculateNextPosValues();
    rotateArrow();
    this->setPos(nextPosX,nextPosY);
    drawArrow();
}
