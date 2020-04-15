#include "Game.h"

char Game::console_input_value = '\0';
std::string Game::console_output = "";

int Game::player_position = 1;
int Game::player_jump_span = 3;
int Game::player_speed = 1;

bool Game::game_jump_flag = false;
int Game::game_position = Game::game_play_area_size - 1;
int Game::game_mine_pos = 7;
std::deque<bool> Game::game_play_area(Game::game_play_area_size, false);

void Game::ClearScreen()
{
    //std::cout << std::endl;
    std::cout << "\033[2J\033[1;1H"<< std::flush;
}

void Game::Display(const std::string& str)
{
    if (!str.length())
        std::cout << console_output << "\n";
    else
        std::cout << str << "\n";
}

void Game::Sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(console_frame_rate));
}

std::string Game::GenerateFrame()
{

    std::string result = "";
    for (auto it = game_play_area.begin(); it != game_play_area.end(); it++)
    {
        result += (*it) ? "T" : "-";
    }

    result[0] = 'x';
    result = "__" + result;
    return result;
}

void Game::Start()
{
    ClearScreen();
    Display("Welcome To DinBIT (press [space] to jump .. 'q' to quit)");
    std::cin.get();

    for (int i = 1; (i * game_mine_pos) <= game_play_area_size; i++)
    {
        game_play_area[(i * 1LL * game_mine_pos) - 1] = true;
    }
    console_output = GenerateFrame();
}

void Game::Loop()
{
    while (1)
    {

        Game::ClearScreen();
        Game::Display();
        Game::Sleep();

        if (!Game::Run()) break;
    }
}

void Game::End()
{
    ClearScreen();
    Display();
    std::cin.get();
}