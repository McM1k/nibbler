
#ifndef OPENGL_INPUTS_HPP
# define OPENGL_INPUTS_HPP

# include <iostream>
# ifdef __APPLE__
#  include <GLUT/glut.h>
#  else
#  include <GL/glut.h>
# endif
# include "../../project/includes/eInputs.hpp"

class Inputs {
public:
    Inputs();
    Inputs(Inputs const &src) = default;
    virtual ~Inputs() = default;
    Inputs &operator=(Inputs const &rhs) = default;

    static eInputs     lastInput;
private:

};

void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
#endif