
#ifndef INPUTS_HPP
# define INPUTS_HPP

# include "../../project/includes/IInput.hpp"
# include <iostream>

class Inputs : public IInput{
public:
    Inputs(void) = default;
    Inputs(Inputs const &src) = default;
    virtual ~Inputs(void) = default;
    Inputs &operator=(Inputs const &rhs) = default;

    int getInput();
private:

};


#endif