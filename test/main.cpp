#include "../src/joyterm.hpp"

using namespace joyterm::style;

int main()
{
    joyterm::init();
    std::cout << MStyle({FgColor::blue, BgColor::red, Style::bold}) << "Hello World!" << MStyle({Style::reset}) << "\n";
}