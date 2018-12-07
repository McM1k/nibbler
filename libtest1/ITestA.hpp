
#ifndef ITESTA_HPP
# define ITESTA_HPP

# include <iostream>

class ITestA {
public:
    virtual void printStuff() = 0;
};

std::ostream &operator<<(std::ostream &o, ITestA const &i);

#endif