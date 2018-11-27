#ifndef ARCHER_H
#define ARCHER_H
#include <QGraphicsRectItem>

class archer:public QGraphicsRectItem
{

    friend class arrow;
public:

    archer();

    void createArrow();
};

#endif // ARCHER_H
