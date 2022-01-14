
#include "game.h"
#include "log.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *gameSnake = new Game();
    gameSnake->Show();
    return a.exec();
}
