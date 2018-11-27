#include "arrow.h"
#include <QTimer>
#include <math.h>
#include <iostream>
arrow::arrow(double vx,double vy):
    Vx{vx},Vy{vy},nextPosX{0},nextPosY{0},/*rotAngle{rotation()},*/t{0.03},g{9.81}
{
    drawArrow();
    startMoving(30);
}

void arrow::drawArrow()
{
    this->setRect(0,0,40,10);
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
   // this->rotAngle=(tan(Vx/Vy)*(180/3.14))-this->rotation();
   // this->setRotation(rotAngle);

    //rotation() returns current rotation in degrees
    std::cout<<(atan(Vx/Vy))<<std::endl;
    double k=(atan(Vx/Vy)*180/3,1415926)+rotation();
    this->setRotation(k);
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
    //resetTransform();
    calculateNextPosValues();
    rotateArrow();
    this->setPos(nextPosX,nextPosY);
    drawArrow();
    }
