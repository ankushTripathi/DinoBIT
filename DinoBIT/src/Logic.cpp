#include "Game.h"

bool Game::GameOverConditions()
{
    return !((player.GetPosition() % game_mine_pos) && ((player.GetPosition() + 1) % game_mine_pos));
}


bool Game::IsInteractionAllowed()
{
    return ((player.GetPosition()+1)% game_mine_pos);
}

bool Game::Run()
{
    game_jump_flag = false;

    if (IsInteractionAllowed() && console->KeyPressed())
    {
        if (console->IsExitKey())
        {
            console->SetOutput("Exiting");
            return false;
        }
        else if (console->IsJumpKey())
        {
            game_jump_flag = true;
            player.Jump();
        }
    }

    Move();
    
    std::string str = GenerateFrame();
    if (game_jump_flag) str += "\n JUMPED !";

    if (GameOverConditions())
    {
        str += "\nGame Over";
        console->SetOutput(str);
        return false;
    }

    console->SetOutput(str);
    return true;
}


void Game::Move()
{
    if (!game_jump_flag)
        player.Run();

    game_play_area.pop_front();
    game_position++;

    if ((game_position + 1)% game_mine_pos == 0)
        game_play_area.push_back(true);
    else
        game_play_area.push_back(false);

    if (game_jump_flag)
    {
        int j = player.GetJumpSpan();

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