#include "arrow.h"
#include <QTimer>
#include <math.h>
arrow::arrow(double vx,double vy):
    Vx{vx},Vy{vy},nextPosX{0},nextPosY{0},rotAngle{0},t{0.03},g{9.81}
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
    this->rotAngle=(tan(Vx/Vy)*(180/3.14))-this->rotAngle;
    this->setRotation(rotAngle);
    this->rotAngle=(tan(Vx/Vy)*(180/3.14));
}

void arrow::calculateNextPosValues()
{
    Vx=Vx;
    Vy=Vy-(g*t);
    nextPosX=this->x()+Vx*t;
    nextPosY=this->y()-Vy-(g*t*t*0.5);
}

void arrow::move()
{
    hideArrow();
    calculateNextPosValues();
    rotateArrow();
    this->setPos(nextPosX,nextPosY);
    drawArrow();
    }
