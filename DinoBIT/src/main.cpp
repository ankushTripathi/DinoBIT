#include "Game.h"

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Game::Start();
    Game::Loop();
    Game::End();
}