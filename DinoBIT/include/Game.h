#pragma once
#include <iostream>
#include<thread>
#include<chrono>
#include <conio.h>
#include <string>
#include <deque>

class Game
{
public:

    static const int console_frame_rate = 400;
    static char console_input_value;
    static const char console_exit_key = 'q';
    static const char console_jump_key = ' ';
    static std::string console_output;

    static int player_position;
    static int player_speed;
    static int player_jump_span;

    static bool game_jump_flag;
    static int game_position;
    static int game_mine_pos;
    static const int game_play_area_size = 15;
    static std::deque<bool> game_play_area;

    static void ClearScreen();
    static void Display(const std::string& str = "");
    static void Sleep();


    static void Move();
    static std::string GenerateFrame();

    static void Start();
    static bool Run();
    static void Loop();
    static void End();
};