#include "Game.h"

Console* Game::console = ConsoleFactory::GetConsole();
Player Game::player = Player();

std::mt19937 Game::eng{ std::random_device{}() };

bool Game::jump_flag = false;
int Game::last_frame = Game::play_area_size - 1;
int Game::last_tree_position = 0;
std::deque<bool> Game::play_area(Game::play_area_size, false);

std::string Game::GenerateFrame()
{

    std::string result = "";
    for (auto it = play_area.begin(); it != play_area.end(); it++)
    {
        result += (*it) ? TREE_SYMBOL : BLANK_SYMBOL;
    }

    result[0] = DINO_SYMBOL;
    result = std::string(INITAL_PADDING, BLANK_SYMBOL) + result;
    return result;
}

void Game::Start()
{
    console->ClearScreen();
    console->Display("Welcome To DinBIT (press [space] to jump .. 'q' to quit)");
    std::cin.get();

    for (int i = 1;i < play_area_size; i++)
    {
        if (ShouldPlaceTree(i))
        {
            play_area[i] = true;
            last_tree_position = i;
        }
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
