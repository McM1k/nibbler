
#ifndef NIBBLER_PARTB_HPP
#define NIBBLER_PARTB_HPP

#include <iostream>

class PartB {
public:
    PartB() = default;

    std::string returnString();

};

extern "C" std::string saySomethingB();

std::ostream & operator<<(std::ostream & o, PartB const & i);

#endif
