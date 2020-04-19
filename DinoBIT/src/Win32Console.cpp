#ifdef _WIN32
#include "Config.h"
#include "Win32Console.h"

Win32Console::Win32Console()
{
    frame_rate = MAX_FRAME_RATE;
    input_value = '\0';
    output = "";
}

void Win32Console::ClearScreen()
{
    std::cout << "\033[2J\033[1;1H" << std::flush;
}

void Win32Console::Display(const std::string& str)
{
    if (!str.length())
        std::cout << output << "\n";
    else
        std::cout << str << "\n";
}

void Win32Console::Sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(frame_rate));
}

void Win32Console::SetOutput(std::string output)
{
    this->output = output;
}

void Win32Console::DecrementFameRate()
{
    this->frame_rate -= FRAME_RATE_REDUCTION;
}

void Win32Console::WaitForInput()
{
    std::cin.get(input_value);
}

bool Win32Console::KeyPressed()
{
    bool result = _kbhit();
    if (result) input_value = _getch();
    return result;
}

bool Win32Console::IsExitKey()
{
    return (input_value == exit_key);
}

bool Win32Console::IsJumpKey()
{
    return (input_value == jump_key);
}


Win32Console::~Win32Console()
{
}

#endif // _WIN32