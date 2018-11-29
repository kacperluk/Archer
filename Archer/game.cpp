#include "game.h"
#include "archer.h"
#include "arrow.h"
void game::mouseReleaseEvent(QMouseEvent *event)
{
    int vox=pressX-event->globalX();
    int voy=-(pressY-event->globalY());
    bowman->createArrow(vox,voy);
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
}
