#pragma once
#ifdef _WIN64

#include "Win32Console.h"

class Win64Console :
	public Win32Console
{
public :
	void ClearScreen() override;
};

#endif

