#include "MStyle.hpp"

joyterm::style::MStyle::MStyle(std::vector <int> _style)
    :style(_style)
{}

void joyterm::style::MStyle::act(std::ostream &os)
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

std::ostream& operator<<(std::ostream& os, joyterm::style::MStyle man)
{
    man.act(os);
    return os;
}