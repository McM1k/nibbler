
#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# define GENERIC_BORDER '#'
# define HORIZONTAL_BORDER
# define VERTICAL_BORDER
# define NW_CORNER_BORDER
# define NE_CORNER_BORDER
# define SE_CORNER_BORDER
# define SW_CORNER_BORDER
# define GRASS ' '
# define FRUIT '\''
# define OBSTACLE '@'
# define GENERIC_SNAKE_PART '*'
# define HORIZONTAL_SNAKE_PART
# define VERTICAL_SNAKE_PART
# define NW_SNAKE_PART
# define NE_SNAKE_PART
# define SE_SNAKE_PART
# define SW_SNAKE_PART
# define N_SNAKE_HEAD
# define E_SNAKE_HEAD
# define S_SNAKE_HEAD
# define W_SNAKE_HEAD

# include "../../project/includes/IEntity.hpp"
# include "../../project/includes/Map.hpp"
# include "../../project/includes/UI.hpp"
# include <iostream>
# include <ncurses.h>

class Display : public IEntity{
public:
    Display(void) = default;
    Display(Display const &src) = default;
    virtual ~Display(void);
    Display &operator=(Display const &rhs) = default;

    Display(int x, int y);

    void display(Map const &map, UI const &gameInfo);

    class UnableToDeleteWindowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
private:
    void printSnake(const std::list<Bloc *> snake);
    void printFruit(const Bloc *fruit);
    void printObstacles(const std::list<Bloc *> &obstacles);

    WINDOW      *window;
    int         red_colour;
    int         green_colour;
    int         yellow_colour;

};

#endif