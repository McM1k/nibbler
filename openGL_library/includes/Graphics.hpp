
#ifndef OPENGL_GRAPHICS_HPP
# define OPENGL_GRAPHICS_HPP

# include <iostream>
# include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//# include "OpenGLUT-0.6.3/openglut.h"
# include "../../project/includes/IGraphics.hpp"
# include "../includes/Displayer.hpp"
# include "../includes/Inputs.hpp"

class Graphics : public IGraphics{
public:
    Graphics() = default;
    Graphics(Graphics const &src) = default;
    virtual ~Graphics(void) = default;
    Graphics &operator=(Graphics const &rhs) = default;

    Graphics(int x, int y);

    void display(Map const &map, UI const &gameInfo);
    eInputs getInput() const;

private:
    int         xSize;
    int         ySize;
    int         windowIdentifier;
    Displayer   displayer;
    Inputs      inputs;
};

extern "C" {
Graphics *newGraphics(int x, int y);
void deleteGraphics(Graphics *graphics);
}


#endif