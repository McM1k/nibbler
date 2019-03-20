
#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

# include <iostream>
# include ""
#include "../../project/includes/IGraphics.hpp"

class Graphics {
public:
    Graphics(void) = default;
    Graphics(Graphics const &src) = default;
    virtual ~Graphics(void) = default;
    Graphics &operator=(Graphics const &rhs) = default;

private:

};


#endif