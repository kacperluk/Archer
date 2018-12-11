#include "game.h"
#include "archer.h"
#include "arrow.h"
#include "enemy.h"

#include <thread>
#include <iostream>
#include <Windows.h>
#include <chrono>
void game::mouseReleaseEvent(QMouseEvent *event)
{
<<<<<<< HEAD
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
=======
    int vox=pressX-event->globalX();
    int voy=-(pressY-event->globalY());
    createArrow(vox/3,voy/3);
}


>>>>>>> 8382021a47fb9d7a7a40ff32300a9578e1499c96

void game::mousePressEvent(QMouseEvent *event)
{
    pressX=event->globalX();
    pressY=event->globalY();
}
void game::createScene()
{
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    this->setScene(scene);
}
void game::createArcher()
{
    bowman=new archer();
    scene->addItem(bowman);
    itemsList.push_back(bowman);
}
game::game()
{
    createScene();
    createArcher();
    createEnemy();
}
void game::createArrow(int V0x,int V0y)
{
 arrow *arrow1=new arrow(V0x,V0y,this);
 scene->addItem(arrow1);
 itemsList.push_back(enemy1);
 arrow1->setPos(bowman->x(),bowman->y());
}
void game::createEnemy()
{
    enemy1=new enemy;
    scene->addItem(enemy1);
    itemsList.push_back(enemy1);
}

