#include <QApplication>
#include "game.h"




int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    game *Game=new game();
    Game->show();


    return a.exec();
}
