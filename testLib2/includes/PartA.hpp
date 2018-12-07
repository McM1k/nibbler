
#ifndef NIBBLER_PARTA_HPP
#define NIBBLER_PARTA_HPP

#include <iostream>

class PartA {
public:
    PartA() = default;

    std::string returnString();
};

extern "C" std::string saySomethingA();

std::ostream & operator<<(std::ostream & o, PartA const & i);


#endif
