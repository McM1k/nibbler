
#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# define GENERIC_BORDER '#'
# define VERTICAL_BORDER '|'
# define HORIZONTAL_BORDER '-'
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
# define HORIZONTAL_SNAKE_PART u8"\u2501"
# define VERTICAL_SNAKE_PART u8"\u2503"
# define NW_SNAKE_PART u8"\u251B"
# define NE_SNAKE_PART u8"\u2517"
# define SE_SNAKE_PART u8"\u250F"
# define SW_SNAKE_PART u8"\u2513"

# define NE_SNAKE_HEAD '\u2BA1'
# define NS_SNAKE_HEAD u8"\u2B63"
# define NW_SNAKE_HEAD '\u2BA0'
# define EN_SNAKE_HEAD '\u2BA4'
# define ES_SNAKE_HEAD '\u2BA4'
# define EW_SNAKE_HEAD u8"\u2B60"
# define SN_SNAKE_HEAD u8"\u2B61"
# define SE_SNAKE_HEAD '\u2BA3'
# define SW_SNAKE_HEAD '\u2BA2'
# define WN_SNAKE_HEAD '\u2BA5'
# define WE_SNAKE_HEAD u8"\u2B62"
# define WS_SNAKE_HEAD '\u2BA7'

# include "../../project/includes/IEntity.hpp"
# include "../../project/includes/Map.hpp"
# include "../../project/includes/UI.hpp"
# include <iostream>

# include <ncurses.h>
# include <clocale>

class Display : public IEntity{
public:
    Display() = default;
    Display(Display const &src) = default;

    virtual ~Display();
    Display &operator=(Display const &rhs) = default;

    Display(int x, int y);

    void display(Map const &map, UI const &gameInfo) override;

    class UnableToDeleteWindowException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class BrokenSnakeException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
    void printSnake(std::list<Bloc> snake);
    void printFruit(Bloc fruit);
    void printObstacles(std::list<Bloc> obstacles);
    void printBorders(int x, int y);

    WINDOW      *window;
    int         red_colour;
    int         green_colour;
    int         yellow_colour;
    int         xSize;
    int         ySize;

};

extern "C" Display *newDisplay(int x, int y);
extern "C" void deleteDisplay(Display *display);

#endif