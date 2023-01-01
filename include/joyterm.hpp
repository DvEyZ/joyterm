#pragma once

#include <iostream>
#include <string>
#include <vector>

#ifdef WIN32
    #include <windows.h>
#endif

namespace joyterm
{
    static void init()
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
    namespace style
    {
        struct FgColor
        {
            enum fc
            {
                black = 30, red = 31, green = 32, yellow = 33, blue = 34, magenta = 35, cyan = 36, white = 37, _default = 39,
                b_black = 90, b_red = 91, b_green = 92, b_yellow = 93, b_blue = 94, b_magenta = 95, b_cyan = 96, b_white = 97
            };
        };

        struct BgColor
        {
            enum bc
            {
                black = 40, red = 41, green = 42, yellow = 43, blue = 44, magenta = 45, cyan = 46, white = 47, _default = 49,
                b_black = 100, b_red = 101, b_green = 102, b_yellow = 103, b_blue = 104, b_magenta = 105, b_cyan = 106, b_white = 107
            };
        };

        struct Style
        {
            enum style
            {
                reset = 0, bold = 1, dim = 2, italic = 3, underline = 4, blink = 5, inverse = 7, hidden = 8, strikethrough = 9
            };
        };

        class MStyle
        {
        public:
            MStyle(std::vector<int> _style)
                :style(_style)
            {}

            void act(std::ostream& os)
            {
                os << "\033[" <<
                    [this] () -> std::string 
                    {
                        if(style.size() == 1) return std::to_string(style[0]);
                        else
                        {
                            std::string temp;
                            for(auto i : style)
                            {
                                temp += std::to_string(i) + ";";
                            }
                            temp.erase(temp.end() - 1);
                            return temp;
                        }
                    } ()
                << "m";
            }

        private:
            std::vector <int> style;
        };

        static std::ostream& operator<<(std::ostream& os, joyterm::style::MStyle man)
        {
            man.act(os);
            return os;
        }
    }
}