#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsRectItem>
#include <QObject>

class arrow:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    double Vx;
    double Vy;
    double nextPosX;
    double nextPosY;
    //double rotAngle;

    const double t;
    const double g;

    arrow(double vx,double vy);
    void drawArrow();
    void hideArrow();
    void startMoving(int ms);
    void rotateArrow();
    void calculateNextPosValues();

public slots:
    void move();

};
#endif // ARROW_H
