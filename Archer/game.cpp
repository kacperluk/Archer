#include "game.h"
#include "archer.h"
#include "arrow.h"
#include "enemy.h"
void game::mouseReleaseEvent(QMouseEvent *event)
{
    int vox=pressX-event->globalX();
    int voy=-(pressY-event->globalY());
    createArrow(vox/3,voy/3);
}
void game::mousePressEvent(QMouseEvent *event)
{
    pressX=event->globalX();
    pressY=event->globalY();
}


game::game()
{
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    this->setScene(scene);
    archer *b=new archer();
    bowman=b;
    scene->addItem(bowman);
    enemy *enemy1=new enemy;
    scene->addItem(enemy1);
    enemy1->setPos(scene->width()/2,scene->height()/2);
}
void game::createArrow(int V0x,int V0y)
{
 arrow *arrow1=new arrow(V0x,V0y);
 scene->addItem(arrow1);
 arrow1->setPos(bowman->x(),bowman->y());
}
