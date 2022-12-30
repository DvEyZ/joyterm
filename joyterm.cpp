#include "joyterm.hpp"

void joyterm::init()
{
#ifdef WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(h , &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    mode |= DISABLE_NEWLINE_AUTO_RETURN;            
    SetConsoleMode(h, mode);
#endif
}