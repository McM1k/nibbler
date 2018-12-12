
#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# define GENERIC_BORDER '#'
# define LEFT_BORDER '\u258C'
# define RIGHT_BORDER '\u2590'
# define UP_BORDER '\u2580'
# define DOWN_BORDER '\u2584'
# define NW_CORNER_BORDER '\u259B'
# define NE_CORNER_BORDER '\u259C'
# define SE_CORNER_BORDER '\u259F'
# define SW_CORNER_BORDER '\u2599'

# define GRASS ' '
# define FRUIT '\''
# define OBSTACLE '@'

# define GENERIC_SNAKE_PART '*'
# define HORIZONTAL_SNAKE_PART '\u2501'
# define VERTICAL_SNAKE_PART '\u2503'
# define NW_SNAKE_PART '\u251B'
# define NE_SNAKE_PART '\u2517'
# define SE_SNAKE_PART '\u250F'
# define SW_SNAKE_PART '\u2513'

# define NE_SNAKE_HEAD '\u2BA1'
# define NS_SNAKE_HEAD '\u2B63'
# define NW_SNAKE_HEAD '\u2BA0'
# define EN_SNAKE_HEAD '\u2BA4'
# define ES_SNAKE_HEAD '\u2BA4'
# define EW_SNAKE_HEAD '\u2B60'
# define SN_SNAKE_HEAD '\u2B61'
# define SE_SNAKE_HEAD '\u2BA3'
# define SW_SNAKE_HEAD '\u2BA2'
# define WN_SNAKE_HEAD '\u2BA5'
# define WE_SNAKE_HEAD '\u2B62'
# define WS_SNAKE_HEAD '\u2BA7'

# include "../../project/includes/IEntity.hpp"
# include "../../project/includes/Map.hpp"
# include "../../project/includes/UI.hpp"
# include <iostream>
# include <ncurses.h>
# include <locale.h>

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
    class BrokenSnakeException : public std::exception {
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