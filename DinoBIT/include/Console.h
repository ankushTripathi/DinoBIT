#pragma once
#include "Config.h"

class Console
{
protected:

    int frame_rate;
    char input_value;
    static const char exit_key = CONSOLE_EXIT_KEY;
    static const char jump_key = CONSOLE_JUMP_KEY;
    std::string output;

public:

    virtual void ClearScreen() = 0;
    virtual void Display(const std::string& str = "") = 0;
    virtual void Sleep() = 0;
    
    virtual bool KeyPressed() = 0;
    virtual bool IsExitKey() = 0;
    virtual bool IsJumpKey() = 0;

    virtual void SetOutput(std::string) = 0;
    virtual void DecrementFameRate() = 0;
};

