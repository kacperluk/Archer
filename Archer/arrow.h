#ifndef ARROW_H
#define ARROW_H
#include "game.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>




class arrow:public QObject,public QGraphicsRectItem
{
    Q_OBJECT
    friend class enemy;
    friend class game;
public:
    game *gamePtr;
    QTimer *timer;
    double Vx;
    double Vy;
    double nextPosX;
    double nextPosY;
    double arrowHeadX;
    double arrowHeadY;
    double rotAngle;
    const double t;
    const double g;
    const double pi;

    arrow(double vx,double vy,game *ptr);
    void drawThis();
    void hideThis();

    void setTimerForMove(int ms);
    void calculateNextPosValues();


    void checkArrowPos();
    bool checkSceneBorders();
    bool checkCollision();
public slots:
    void move();
};
#endif // ARROW_H
