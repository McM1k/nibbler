
#ifndef IINPUT_HPP
# define IINPUT_HPP

# include <iostream>

class IInputs {
public:
    virtual int getInput() const = 0;
};

#endif