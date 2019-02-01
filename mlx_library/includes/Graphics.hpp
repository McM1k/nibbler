
#ifndef MLX_GRAPHICS_HPP
# define MLX_GRAPHICS_HPP

# include "../../project/includes/IGraphics.hpp"
#include "MlxData.hpp"
#include "Inputs.hpp"
#include "Display.hpp"
# include <iostream>
# include <mlx.h>

class Graphics : public IGraphics {
public:
    Graphics(void) = default;
    Graphics(int x, int y);
    Graphics(Graphics const &src) = default;
    virtual ~Graphics(void) = default;
    Graphics &operator=(Graphics const &rhs) = default;

    void display(Map const &map, UI const &gameInfo);
    eInputs getInput() const;

    class UnableToInitMlx : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class UnableToInitWindow : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class UnableToInitImageAddress : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class UnableToInitImageContent : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
    int         xSize;
    int         ySize;
    MlxData     mlxData;
    Inputs      inputs;
    Display     display1;
};

extern "C" {
Graphics *newGraphics(int x, int y);
void deleteGraphics(Graphics *graphics);
}

#endif