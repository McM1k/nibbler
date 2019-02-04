
#ifndef MLX_DISPLAY_HPP
# define MLX_DISPLAY_HPP

# include <iostream>
# include <mlx.h>
#include "MlxData.hpp"
#include "../../project/includes/Map.hpp"
#include "../../project/includes/UI.hpp"

class Display {
public:
    Display(void) = default;
    Display(MlxData _mlxData);
    Display(Display const &src) = default;
    virtual ~Display(void) = default;
    Display &operator=(Display const &rhs) = default;

    void    display(Map &map, UI &ui);

private:
    void    put_pixel(int x, int y, char transparency, char red, char green, char blue);
    void    clean_image();

    void    print_background(Map &map);
    void    print_borders(Map &map);
    void    print_obstacles(Map &map);
    void    print_fruit(Map &map);
    void    print_snake(Map &map);

    MlxData mlxData;

};


#endif