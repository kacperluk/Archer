#ifndef GAME_H
#define GAME_H
#include "archer.h"
#include <QGraphicsView>
#include <QMouseEvent>
class game:public QGraphicsView
{
public:
    archer *bowman;
    QGraphicsScene *scene;
    int pressX;
    int pressY;
    void createArrow();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    game();
};

#endif // GAME_H
