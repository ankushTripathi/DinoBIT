#pragma once
#include <string>
#include <deque>

#include "Player.h"
#include "ConsoleFactory.h"
#include "Config.h"

class Game
{
public:

    static Console* console;
    static Player player;

    static bool game_jump_flag;
    static int game_position;
    static int game_mine_pos;
    static const int game_play_area_size = PLAY_AREA_SIZE;
    static std::deque<bool> game_play_area;

    static bool GameOverConditions();
    static bool IsInteractionAllowed();
    static void Move();
    static std::string GenerateFrame();

    static void Start();
    static bool Run();
    static void Loop();
    static void End();
};