
#ifndef IINPUT_HPP
# define IINPUT_HPP

# include <iostream>

class IInput {
public:
    virtual int getInput() const = 0;
};

#endif