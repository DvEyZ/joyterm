# JoyTerm  
JoyTerm is a simple C++ library for colorful terminal output.
## Usage
JoyTerm is header-only library, so you just `#include <joyterm.hpp>` and that's it!
### Styles
```c++
#include <iostream>
#include <joyterm.hpp>

int main()
{
    joyterm::init();
    std::cout << joyterm::style::MStyle({FgColor::blue, BgColor::red, Style::bold}) << "Hello World!" << joyterm::style::MStyle({Style::reset}) << "\n";
}
```