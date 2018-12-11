#ifndef GAME_H
#define GAME_H
#include "archer.h"
#include "enemy.h"
#include <QGraphicsView>
#include <QMouseEvent>
class game:public QGraphicsView
{
    friend class arrow;
public:
    archer *bowman;
    enemy *enemy1;
    QGraphicsScene *scene;
    QList<QGraphicsItem*>itemsList;
    int pressX;
    int pressY;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void createScene();
    void createArcher();
    void createArrow(int Vox,int Voy);
    void createEnemy();
    game();
};

#endif // GAME_H
