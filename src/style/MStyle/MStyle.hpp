#pragma once

#include <string>
#include <iostream>
#include <vector>

namespace joyterm::style
{
    class MStyle
    {
    public:
        MStyle(std::vector<int> style);
        void act(std::ostream& os);
    private:
        std::vector <int> style;
    };
}

std::ostream& operator<<(std::ostream& os, joyterm::style::MStyle man);