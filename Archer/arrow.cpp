#include "arrow.h"
#include "enemy.h"
#include <math.h>
#include <QGraphicsScene>
#include <QList>
#include <iostream>
arrow::arrow(double vx,double vy,game *ptr):
    gamePtr{ptr},
    timer{nullptr},
    Vx{vx},
    Vy{vy},
    nextPosX{0},
    nextPosY{0},
    arrowHeadX{0},
    arrowHeadY{0},
    rotAngle{0},
    t{0.01},
    g{9.81},
    pi{3.141592}
{
    drawArrow();
    setTimerForMove(t*300);
}

void arrow::drawArrow()
{
    setPos(nextPosX,nextPosY);
    setRotation(rotAngle);
    setRect(0,0,40,1);
}
void arrow::hideArrow()
{
    this->setRect(0,0,0,0);
}
void arrow::setTimerForMove(int ms)
{
    timer = new QTimer();
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
    //arrow head position
    arrowHeadX=x()+Vx/sqrt(pow(Vx,2)+pow(Vy,2))*40 ;
    arrowHeadY=y()-Vy/sqrt(pow(Vx,2)+pow(Vy,2))*40;
}
void arrow::checkArrowPos()
{
    if(checkCollision()==true)
    {
        delete timer;
        delete gamePtr->enemy1;
        gamePtr->createEnemy();
        delete this;
    }
    else if(checkSceneBorders()==true)
    {
        delete timer;
        delete this;
    }
}
bool arrow::checkSceneBorders()
{

    if(x()>scene()->width()||x()<0)
    {
        return true;
    }
    if(y()>scene()->height())
    {
        return true;
    }
    return false;
}
bool arrow::checkCollision()
{
    double enemyX=gamePtr->enemy1->getEnemyX();
    double enemyY=gamePtr->enemy1->getEnemyY();
    if(arrowHeadX>=enemyX && arrowHeadX<=enemyX+20)
        if(arrowHeadY>=enemyY && arrowHeadY<=enemyY+50)
        {
            return true;
        }
    return false;

}
void arrow::move()
{
    hideArrow();
    calculateNextPosValues();
    drawArrow();
    checkArrowPos();
}
