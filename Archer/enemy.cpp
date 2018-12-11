#include "game.h"
#include "archer.h"
#include "arrow.h"
#include "enemy.h"

#include <thread>
#include <iostream>
#include <Windows.h>
#include <chrono>

enemy::enemy()
{
    setRandPos();
    drawThis();
}

void enemy::drawThis()
{

    //random position on the scene

    this->setRect(0,0,20,50);
}

void enemy::hideThis()
{
    this->setRect(0,0,0,0);
}

void enemy::setRandPos()
{
    int x=rand()%800;
    int y=rand()%600;
    this->setPos(x,y);
}

double enemy::getEnemyX()
{
    return x();
}

double enemy::getEnemyY()
{
    return y();
}
