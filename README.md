# JoyTerm  
JoyTerm is a C++ library for colorful terminal output.
## Usage
JoyTerm is header-only library, so you just `#include <joyterm.hpp>` and that's it!
### Styles
```c++
#include <iostream>
#include <joyterm.hpp>

using namespace joyterm::style;
int main()
{
    joyterm::init();
    std::cout << MStyle({FgColor::blue, BgColor::red, Style::bold}) << "Hello World!" << MStyle({Style::reset}) << "\n";
}
```