#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>

class enemy:public QGraphicsRectItem
{
public:
    enemy();
    void drawThis();
    void hideThis();
    void setRandPos();
    double getEnemyX();
    double getEnemyY();
};

#endif // ENEMY_H
