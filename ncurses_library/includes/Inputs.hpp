
#ifndef INPUTS_HPP
# define INPUTS_HPP

# include "../../project/includes/IInput.hpp"
# include <iostream>
# include <ncurses.h>

class Inputs : public IInput{
public:
    Inputs(void) = default;
    virtual ~Inputs(void) = default;

    int getInput() const;

private:
    Inputs(Inputs const &src) = default;

    Inputs &operator=(Inputs const &rhs) = default;

};


#endif