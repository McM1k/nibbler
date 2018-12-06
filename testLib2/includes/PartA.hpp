
#ifndef NIBBLER_PARTA_HPP
#define NIBBLER_PARTA_HPP


#include <iostream>

class PartA {
public:
    PartA();

    PartA(int);

    PartA(PartA const &src);

    virtual ~PartA();

    PartA &operator=(PartA const &);

private:
};

std::ostream &operator<<(std::ostream &o, PartA const &i);


#endif
