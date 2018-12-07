
#ifndef NIBBLER_PARTA_HPP
#define NIBBLER_PARTA_HPP

#include <iostream>
#include "IPartA.hpp"

class PartA : public IPartA {
public:
    PartA() = default;

    ~PartA() = default;

    std::string saySomething() const;
};

extern "C" {
    PartA   *newPartA();

    void    destroyPartA(PartA *partA);
}

std::ostream & operator<<(std::ostream & o, PartA const & i);

#endif
