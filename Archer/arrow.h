#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
class arrow:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    double Vx;
    double Vy;
    double nextPosX;
    double nextPosY;
    double rotAngle;
    const double t;
    const double g;
    const double pi;

    arrow(double vx,double vy);
    void drawArrow();
    void hideArrow();
    void setTimerForMove(int ms);
    void calculateNextPosValues();
    void checkSceneBorders();

public slots:
    void move();
};
#endif // ARROW_H
