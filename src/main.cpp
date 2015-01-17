#include "Game.hpp"

int main()
{
    Game* clong = new Game();
    
    int returnValue = clong->run();
    
    delete clong;

    return returnValue;
}
