
#ifndef MLX_DISPLAY_HPP
# define MLX_DISPLAY_HPP

# include <iostream>
# include <mlx.h>
#include "MlxData.hpp"
#include "../../project/includes/Map.hpp"
#include "../../project/includes/UI.hpp"

# define NO_COLOR       0
# define FRUIT_COLOR_1  1
# define FRUIT_COLOR_2  2
# define SNAKE_COLOR_1  3
# define SNAKE_COLOR_2  4
# define ROCK_COLOR_1   5
# define ROCK_COLOR_2   6

class Display {
public:
    Display(void) = default;
    Display(MlxData _mlxData);
    Display(Display const &src) = default;
    virtual ~Display(void) = default;
    Display &operator=(Display const &rhs) = default;

    void    display(Map const &map, UI const &ui);

    class BrokenSnakeException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
    void    put_pixel(int x, int y, char transparency, char red, char green, char blue);
    void    put_square(int xSquare, int ySquare, char img[10][10], Map::eDirection direction);
    void    select_color(int x, int y, char color);
    void    clean_image();

    void    print_background(Map const &map);
    void    print_obstacles(std::list<Bloc> obstacles);
    void    print_fruit(Bloc fruit);
    void    print_snake(std::list<Bloc> snake);

    char fruit_img[10][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,1,0,0,0,0},
            {0,0,0,0,1,1,0,0,0,0},
            {0,0,0,1,1,2,1,0,0,0},
            {0,0,1,1,1,2,1,1,0,0},
            {0,0,1,1,2,2,1,1,0,0},
            {0,0,0,1,1,1,1,0,0,0},
            {0,0,0,0,1,1,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}
    };
    char tail_img[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,3},
        {0,0,0,0,0,0,3,3,3,3},
        {0,0,0,3,3,3,3,3,3,3},
        {0,0,0,0,0,0,0,0,3,3},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    char head_img[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,3,3,3,0,0,0,0},
        {0,3,3,3,3,3,3,0,0,0},
        {3,3,3,3,4,4,3,3,0,0},
        {3,3,3,3,3,3,3,3,3,0},
        {3,3,3,3,3,3,3,3,3,0},
        {3,3,3,3,4,4,3,3,0,0},
        {0,3,3,3,3,3,3,0,0,0},
        {0,0,0,3,3,3,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    char body_center_img[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,3,3,3,3,0,0,0},
        {0,0,0,3,3,3,3,0,0,0},
        {0,0,0,3,3,3,3,0,0,0},
        {0,0,0,3,3,3,3,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}

    };

    char body_junction_img[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,3,3,3},
        {0,0,0,0,0,0,0,3,3,3},
        {0,0,0,0,0,0,0,3,3,3},
        {0,0,0,0,0,0,0,3,3,3},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    char rock_img[10][10] = {
            {0,0,6,5,5,6,5,5,0,0},
            {0,5,5,6,5,5,6,6,5,0},
            {6,5,5,6,5,5,5,6,5,5},
            {6,6,5,6,5,6,5,5,5,5},
            {5,5,5,5,6,5,6,5,5,6},
            {5,5,5,5,6,5,6,5,6,5},
            {6,6,6,5,6,5,5,6,5,5},
            {5,5,5,6,5,5,5,5,6,5},
            {0,5,6,5,5,6,5,5,6,0},
            {0,0,6,5,5,5,6,6,0,0}
    };

    MlxData mlxData;

};


#endif