#ifdef _WIN64

#include "Win64Console.h"

void Win64Console::ClearScreen()
{
	std::cout << std::string(100, '\n');
}

#endif // _WIN64
