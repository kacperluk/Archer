#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsRectItem>
#include <QObject>

class arrow:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
    friend class archer;
public:
    double Vx;
    double Vy;
    double rotAngle;
    const double t;
    const double g;
    arrow(double vx,double vy);
public slots:
    void move();
};
#endif // ARROW_H
