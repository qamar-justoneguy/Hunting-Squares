#include "game.hpp"

int main(int argv, char** argc)
{
    Game game("Hunting Squares (PID)", 1280, 620);
    
    game.play();

    return 0;
}