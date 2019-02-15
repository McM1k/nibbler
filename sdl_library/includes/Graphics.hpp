
#ifndef SDL_GRAPHICS_HPP
# define SDL_GRAPHICS_HPP

# include <iostream>
# include <SDL.h>
#include "../../project/includes/IGraphics.hpp"

class Graphics : public IGraphics{
public:
    Graphics(void) = default;
    Graphics(int x, int y);
    Graphics(Graphics const &src) = default;
    virtual ~Graphics(void) = default;
    Graphics &operator=(Graphics const &rhs) = default;

    void display(Map const &map, UI const &gameInfo);
    eInputs getInput() const;

private:
    Display display1;
    Inputs inputs;
};

extern "C" {
Graphics *newGraphics(int x, int y);
void deleteGraphics(Graphics *graphics);
}

#endif