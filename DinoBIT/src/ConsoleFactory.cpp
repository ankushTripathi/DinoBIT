#include "ConsoleFactory.h"

Console* ConsoleFactory::GetConsole()
{
#ifdef __unix
	return new Console();
#endif // __unix
#ifdef __APPLE__
	return new Console();
#endif // __APPLE__
#ifdef _WIN64 
	return new Win64Console();
#endif	//_WIN64
#ifdef _WIN32 
	return new Win32Console();
#endif // _WIN32 
}