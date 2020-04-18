#pragma once
#ifdef _WIN32

#include<iostream>
#include <conio.h>
#include<thread>
#include<chrono>
#include <string>

#include "Console.h"

class Win32Console : public Console
{

public :

    Win32Console();

    void ClearScreen();
    void Display(const std::string& str);
    void Sleep();

    void SetOutput(std::string output);
    void DecrementFameRate();

    bool KeyPressed();
    bool IsExitKey();
    bool IsJumpKey();

    ~Win32Console();
};

#endif // _WIN32