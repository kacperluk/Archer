#ifndef ARCHER_H
#define ARCHER_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QMouseEvent>

class archer:public QGraphicsRectItem
{

    friend class arrow;
public:

    archer();
void createArrow(int V0x,int V0y);
};

#endif // ARCHER_H
