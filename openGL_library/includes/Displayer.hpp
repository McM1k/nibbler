
#ifndef OPENGL_DISPLAYER_HPP
# define OPENGL_DISPLAYER_HPP

# include <iostream>
# ifdef __APPLE__
#  include <GLUT/glut.h>
#  else
#  include <GL/glut.h>
# endif
# include "../../project/includes/Map.hpp"
# include "../../project/includes/UI.hpp"

class Displayer {
public:
    Displayer() = default;
    Displayer(Displayer const &src) = default;
    virtual ~Displayer() = default;
    Displayer &operator=(Displayer const &rhs) = default;

    Displayer(int x, int y);

    static Map &map;
    static UI &gameInfo;

private:
    int     xSize;
    int     ySize;
};

void renderScene();
#endif