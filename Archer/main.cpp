#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "archer.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene=new QGraphicsScene;
    QGraphicsView *view=new QGraphicsView;
    view->setScene(scene);
    scene->setSceneRect(0,0,800,600);
    view->show();
    archer *bowman=new archer();
    scene->addItem(bowman);

    bowman->createArrow();


    return a.exec();
}
