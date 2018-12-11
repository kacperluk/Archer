#include <QApplication>
#include "game.h"
#include <Windows.h>
#include <thread>
#include <QGraphicsScene>
#include <iostream>
#include <QGraphicsItem>
#include <QList>


#include<stdlib.h>
#include<time.h>
void drawEverything(QList<QGraphicsItem*> *iList,QGraphicsScene *scenePtr )
{
     Sleep(500);
    std::cout<<iList->size()<<" is size "<<std::endl<<std::endl;
    Sleep(500);
    std::cout<<iList->size()<<" is size "<<std::endl<<std::endl;



     for(auto i:*iList)
    {
        scenePtr->removeItem(i);
    }
    Sleep(1000);
    for(auto i:*iList)
    {
        scenePtr->addItem(i);
    }

}
int main(int argc, char *argv[])
{

    srand(time(NULL));
    QApplication a(argc, argv);
    game *Game=new game();

    QGraphicsScene *sceene=Game->scene;
    QList<QGraphicsItem*> *iList=&Game->itemsList;
    std::thread t1(drawEverything,iList,sceene);


    Game->show();
t1.detach();
    return a.exec();


}
