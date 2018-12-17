
#ifndef INPUTS_HPP
# define INPUTS_HPP

# include "../../project/includes/IInput.hpp"
# include <iostream>
# include <ncurses.h>

class Inputs : public IInput{
public:
    Inputs() = default;

    virtual ~Inputs() = default;

    int getInput() const override;

private:
    Inputs(Inputs const &src) = default;

    Inputs &operator=(Inputs const &rhs) = default;

};


#endif