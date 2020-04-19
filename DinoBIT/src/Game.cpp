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

    std::string str = "Current Score :" + std::to_string(player.GetScore()) + "\t High Score :" + std::to_string(player.GetHighScore()) + "\n";
    std::string result = "";
    for (auto it = play_area.begin(); it != play_area.end(); it++)
    {
        result += (*it) ? TREE_SYMBOL : BLANK_SYMBOL;
    }

    result[0] = DINO_SYMBOL;
    result = std::string(INITAL_PADDING, BLANK_SYMBOL) + result;
    return str + result;
}

void Game::Start()
{
    console->ClearScreen();
    console->Display("Welcome To DinBIT (press [space] to jump ..)");
    console->WaitForInput();

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
       
        if (!Run())
        {
            if (ShouldRestart())
                Restart();
            else
                break;
        }
    }
}

bool Game::ShouldRestart()
{
    console->ClearScreen();
    console->Display();
    console->WaitForInput();

    console->ClearScreen();
    console->Display("Press [Enter] to restart, 'q' to quit..");

    console->WaitForInput();

    return !(console->IsExitKey());
}

void Game::Restart()
{
    Game::console = ConsoleFactory::GetConsole();
    Game::player = Player();

    Game::jump_flag = false;
    Game::last_frame = Game::play_area_size - 1;
    Game::last_tree_position = 0;
    Game::play_area = std::deque<bool>(Game::play_area_size, false);

    Game::Start();
}

void Game::End()
{
    console->ClearScreen();
    console->Display();

    console->WaitForInput();

    delete console;
}
