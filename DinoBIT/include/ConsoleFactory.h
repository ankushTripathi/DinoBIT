#pragma once
#include "Win32Console.h"
#include "Win64Console.h"

class ConsoleFactory
{
public:
	static Console* GetConsole();
};

