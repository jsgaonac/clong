#include "Game.hpp"
#include <memory>

int main()
{
    std::unique_ptr<Game> clong(new Game(800, 600, 32, "Clong!"));
    
    int returnValue = clong->run();
    
    return returnValue;
}
