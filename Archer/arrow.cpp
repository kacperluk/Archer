#include "arrow.h"
#include <QTimer>
#include <math.h>
arrow::arrow(double vx,double vy):
    Vx{vx},Vy{vy},t{0.03},g{9.81}
{
    this->setRect(0,0,40,10);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(2000);
}

void arrow::move()
{
    Vx=Vx;
    Vy=Vy-(g*t);
    double nextPosX=this->x()+Vx*t;
    double nextPosY=this->y()-Vy-(g*t*t*0.5);
    rotAngle=(tan(Vx/Vy)*(180/3.14))-rotAngle;
    this->setRotation(rotAngle);
    rotAngle=(tan(Vx/Vy)*(180/3.14));
    this->setPos(nextPosX,nextPosY);
    }
