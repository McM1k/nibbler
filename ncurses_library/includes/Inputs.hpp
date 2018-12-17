
#ifndef INPUTS_HPP
# define INPUTS_HPP

# include "../../project/includes/IInputs.hpp"
# include <iostream>
# include <ncurses.h>

class Inputs : public IInputs {
public:
    Inputs() = default;

    virtual ~Inputs() = default;

    int getInput() const override;

private:
    Inputs(Inputs const &src) = default;

    Inputs &operator=(Inputs const &rhs) = default;

};

extern "C" {
Inputs *newInputs();
void deleteInputs(Inputs *inputs);
}

#endif