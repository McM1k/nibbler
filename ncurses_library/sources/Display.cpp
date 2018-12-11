
#include "../includes/Display.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Display::Display(int x, int y) {
    this->window = newwin(x + 2, y + 7, 0, 0);
    this->red_colour = (COLOR_RED, COLOR_BLACK);
    this->yellow_colour = (COLOR_YELLOW, COLOR_BLACK);
    this->green_colour = (COLOR_GREEN, COLOR_BLACK);
}

Display::~Display() {
    if (!delwin(this->window))
        throw UnableToDeleteWindowException();
}
/* ******************************* */
/*            Accessors            */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
void Display::printSnake(const std::list<Bloc *> snake) {
    for (Bloc *snake_part : snake){
        mvaddch(snake_part->getY() + 1, snake_part->getX() + 1, GENERIC_SNAKE_PART);
    }
}

void Display::printFruit(const Bloc *fruit) {
    if (fruit->getX() >= 0 && fruit->getY() >= 0) {
        mvaddch(fruit->getY() + 1, fruit->getX() + 1, FRUIT);
    }
}

void Display::printObstacles(const std::list<Bloc *> &obstacles) {
    for (Bloc *obstacle_part : obstacles){
        mvaddch(obstacle_part->getY() + 1, obstacle_part->getX() + 1, OBSTACLE);
    }
}

void Display::display(const Map &map, const UI &gameInfo) {
    wclear(this->window);
    wborder(this->window, GENERIC_BORDER, GENERIC_BORDER, GENERIC_BORDER, GENERIC_BORDER, GENERIC_BORDER, GENERIC_BORDER, GENERIC_BORDER, GENERIC_BORDER);
    //wborder(this->window, HORIZONTAL_BORDER, HORIZONTAL_BORDER, VERTICAL_BORDER, VERTICAL_BORDER,
    //        NW_CORNER_BORDER, NE_CORNER_BORDER, SW_CORNER_BORDER, SE_CORNER_BORDER);
    printSnake(map.getSnake());
    printObstacles(map.getObstacles());
    printFruit(map.getFruit());
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */
const char* Display::UnableToDeleteWindowException::what() const throw(){
    return "Unable to delete nCurses window";
}
