#pragma once
#include "Config.h"

class Player
{
protected:

    int position;
    int speed;
    int jump_span;
    int score;
    int high_score;

public :
    
    Player();

    int GetPosition();
    int GetJumpSpan();

    void Run();
    void Jump();

    int GetScore();
    void SetScore(int);

    int GetHighScore();

    ~Player();
};

