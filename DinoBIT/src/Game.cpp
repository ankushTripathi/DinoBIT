#include "Game.h"

Console* Game::console = ConsoleFactory::GetConsole();
Player Game::player = Player();

bool Game::game_jump_flag = false;
int Game::game_position = Game::game_play_area_size - 1;
int Game::game_mine_pos = MAX_TREE_DISTANCE;
std::deque<bool> Game::game_play_area(Game::game_play_area_size, false);

std::string Game::GenerateFrame()
{

    std::string result = "";
    for (auto it = game_play_area.begin(); it != game_play_area.end(); it++)
    {
        result += (*it) ? 'T' : '-';
    }

    result[0] = 'x';
    result = "--" + result;
    return result;
}

void Game::Start()
{
    console->ClearScreen();
    console->Display("Welcome To DinBIT (press [space] to jump .. 'q' to quit)");
    std::cin.get();

    for (int i = 1; (i * game_mine_pos) <= game_play_area_size; i++)
    {
        game_play_area[(i * 1LL * game_mine_pos) - 1] = true;
    }
    console->SetOutput(GenerateFrame());
}

void Game::Loop()
{
    while (1)
    {

        console->ClearScreen();
        console->Display();
        console->Sleep();
       
        if (!Run()) break;
    }
}

void Game::End()
{
    console->ClearScreen();
    console->Display();
    delete console;

    std::cin.get();
}