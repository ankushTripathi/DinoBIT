#pragma once
#include <string>
#include <deque>
#include<random>

#include "Player.h"
#include "ConsoleFactory.h"
#include "Config.h"


class Game
{

private:

    static Console* console;
    static Player player;

    static bool jump_flag;
    static int last_frame;
    static int last_tree_position;
    static const int play_area_size = PLAY_AREA_SIZE;
    static std::deque<bool> play_area;

    static std::mt19937 eng;

    static bool GameOverConditions();
 
    static bool IsLevelUp();
    static void LevelUp();

    static bool ShouldPlaceTree(int);
    static void Move();
    static std::string GenerateFrame();

    static bool Run();

public:

    static void Start();
    static void Loop();
    static void End();
};