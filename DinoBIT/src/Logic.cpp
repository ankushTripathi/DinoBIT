#include "Game.h"

bool Game::GameOverConditions()
{
    return (play_area[0] || play_area[1]);
}

bool Game::IsLevelUp()
{
    return !((last_frame + 1) % (LEVEL_UP_FACTOR * play_area_size));
}


void Game::LevelUp()
{
    console->DecrementFameRate();
}

bool Game::Run()
{
    jump_flag = false;

    if(console->KeyPressed())
    {
        if (console->IsExitKey())
        {
            console->SetOutput("Exiting");
            return false;
        }
        else if (console->IsJumpKey())
        {
            jump_flag = true;
            player.Jump();
        }
    }


     if (IsLevelUp())
    {
         Game::LevelUp();
    }


    Move();
    
    std::string str = GenerateFrame();
    if (jump_flag) str += "\n JUMPED !";

    if (GameOverConditions())
    {
        str += "\nGame Over";
        str += "\n Final Score :" + std::to_string(player.GetScore());
        console->SetOutput(str);
        return false;
    }

    console->SetOutput(str);
    return true;
}


bool Game::ShouldPlaceTree(int frame)
{
    if (frame - last_tree_position >= MAX_TREE_DISTANCE)
        return std::uniform_int_distribution<std::mt19937::result_type>{0,1}(eng);
    
    return false;
}

void Game::Move()
{
    if (!jump_flag)
        player.Run();

    play_area.pop_front();
    last_frame++;

    if (ShouldPlaceTree(last_frame))
    {
        play_area.push_back(true);
        last_tree_position = last_frame;
    }
    else
        play_area.push_back(false);

    if (jump_flag)
    {
        int j = player.GetJumpSpan();

        while (--j)
        {
            play_area.pop_front();
            last_frame++;

            if (ShouldPlaceTree(last_frame))
            {
                play_area.push_back(true);
                last_tree_position = last_frame;
            }
            else
                play_area.push_back(false);
        }
    }
}