#include "Game.h"

bool Game::GameOverConditions()
{
    return !((player_position % game_mine_pos) && ((player_position + 1) % game_mine_pos));
}


bool Game::IsInteractionAllowed()
{
    return ((player_position+1)% game_mine_pos);
}

bool Game::Run()
{
    game_jump_flag = false;

    if (IsInteractionAllowed() && _kbhit())
    {
        if ((console_input_value = _getch()) == console_exit_key)
        {
            console_output = "Exiting";
            return false;
        }
        else if (console_input_value == console_jump_key)
        {
            game_jump_flag = true;
            player_position += player_jump_span;
        }
    }


    if (GameOverConditions())
    {
        console_output = "Game Over";
        return false;
    }

    Move();
    console_output = GenerateFrame();
    if (game_jump_flag) console_output += "\n JUMPED !";

    return true;
}


void Game::Move()
{
    if (!game_jump_flag)
        player_position += player_speed;

    game_play_area.pop_front();
    game_position++;

    if ((game_position + 1)% game_mine_pos == 0)
        game_play_area.push_back(true);
    else
        game_play_area.push_back(false);

    if (game_jump_flag)
    {
        int j = player_jump_span;
        while (--j)
        {
            game_play_area.pop_front();
            game_position++;

            if ((game_position + 1) % game_mine_pos == 0)
                game_play_area.push_back(true);
            else
                game_play_area.push_back(false);
        }
    }
}