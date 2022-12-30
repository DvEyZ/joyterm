# JoyTerm  
JoyTerm is a simple C++ library for colorful terminal output.
## Usage  
### Styles
```c++
#include <iostream>
#include <joyterm.hpp>

int main()
{
    joyterm::init();
    std::cout << MStyle({FgColor::blue, BgColor::red, Style::bold}) << "Hello World!" << MStyle({Style::reset}) << "\n";
}
```