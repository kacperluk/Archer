#ifndef GAME_H
#define GAME_H
#include "archer.h"
#include <QGraphicsView>
#include <QMouseEvent>
class game:public QGraphicsView
{
    friend class arrow;
public:
    archer *bowman;
    QGraphicsScene *scene;
    int pressX;
    int pressY;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void createArrow(int Vox,int Voy);
    game();
};

#endif // GAME_H
