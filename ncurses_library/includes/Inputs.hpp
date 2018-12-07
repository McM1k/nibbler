
#ifndef INPUTS_HPP
# define INPUTS_HPP

# include <iostream>

class Inputs {
public:
    Inputs(void) = default;

    Inputs(Inputs const &src) = default;

    virtual ~Inputs(void) = default;

    Inputs &operator=(Inputs const &rhs) = default;

private:

};


#endif