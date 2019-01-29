/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:48:50 by gboudrie          #+#    #+#             */
/*   Updated: 2019/01/18 15:48:50 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Display.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Display::Display(int x, int y, WINDOW *_window) : xSize(x), ySize(y), window(_window) {}

/* ******************************* */
/*            Accessors            */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
void Display::printSnake(std::list<Bloc> snake) {
    /*
    std::list<Bloc *>::const_iterator prev = snake.begin();
    std::list<Bloc *>::const_iterator next = snake.begin();
    next++;
    for (std::list<Bloc *>::const_iterator it = snake.begin(); it != snake.end(); it++){
        if (it == snake.begin()){ // TAIL
            if ((*it)->getX() == (*next)->getX())
                mvaddch((*it)->getY() + 1, (*it)->getX() + 1, VERTICAL_SNAKE_PART);
            else if ((*it)->getY() == (*next)->getY())
                mvaddch((*it)->getY() + 1, (*it)->getX() + 1, HORIZONTAL_SNAKE_PART);
            else
                throw BrokenSnakeException();
        }
        else{ //BODY
            if ((*prev)->getX() == (*it)->getX() == (*next)->getX())
                mvaddch((*it)->getY() + 1, (*it)->getX() + 1, VERTICAL_SNAKE_PART);
            else if ((*prev)->getY() == (*it)->getY() == (*next)->getY())
                mvaddch((*it)->getY() + 1, (*it)->getX() + 1, HORIZONTAL_SNAKE_PART);
            else if (((*prev)->getX() == (*it)->getX() - 1 || (*next)->getX() == (*it)->getX() - 1) &&
                     ((*prev)->getY() == (*it)->getY() - 1 || (*next)->getY() == (*it)->getY() - 1))
                mvaddch((*it)->getY() + 1, (*it)->getX() + 1, NW_SNAKE_PART);
            else if (((*prev)->getX() == (*it)->getX() + 1 || (*next)->getX() == (*it)->getX() + 1) &&
                     ((*prev)->getY() == (*it)->getY() - 1 || (*next)->getY() == (*it)->getY() - 1))
                mvaddch((*it)->getY() + 1, (*it)->getX() + 1, NE_SNAKE_PART);
            else if (((*prev)->getX() == (*it)->getX() + 1 || (*next)->getX() == (*it)->getX() + 1) &&
                     ((*prev)->getY() == (*it)->getY() + 1 || (*next)->getY() == (*it)->getY() + 1))
                mvaddch((*it)->getY() + 1, (*it)->getX() + 1, SE_SNAKE_PART);
            else if (((*prev)->getX() == (*it)->getX() - 1 || (*next)->getX() == (*it)->getX() - 1) &&
                     ((*prev)->getY() == (*it)->getY() + 1 || (*next)->getY() == (*it)->getY() + 1))
                mvaddch((*it)->getY() + 1, (*it)->getX() + 1, SW_SNAKE_PART);
            else
                throw BrokenSnakeException();
            prev++;
        }
        if (next != snake.end())
            next++;
    }
    //HEAD (might wanna add bools in map to get the intended direction)
    if ((*prev)->getX() == (*next)->getX() - 1)
        mvaddch((*next)->getY() + 1, (*next)->getX() + 1, NS_SNAKE_HEAD);
    else if ((*prev)->getY() == (*next)->getY() + 1)
        mvaddch((*next)->getY() + 1, (*next)->getX() + 1, EW_SNAKE_HEAD);
    else if ((*prev)->getX() == (*next)->getX() + 1)
        mvaddch((*next)->getY() + 1, (*next)->getX() + 1, SN_SNAKE_HEAD);
    else if ((*prev)->getY() == (*next)->getY() - 1)
        mvaddch((*next)->getY() + 1, (*next)->getX() + 1, WE_SNAKE_HEAD);
    else
        throw BrokenSnakeException();
    */

    for (auto snake_part : snake){
        mvaddch(snake_part.getY() + 1, snake_part.getX() + 1, GENERIC_SNAKE_PART);
    }
}

void Display::printFruit(Bloc fruit) {
    if (fruit.getX() >= 0 && fruit.getY() >= 0) {
        mvaddch(fruit.getY() + 1, fruit.getX() + 1, FRUIT);
    }
}

void Display::printObstacles(std::list<Bloc> obstacles) {
    for (auto obstacle_part : obstacles){
        mvaddch(obstacle_part.getY() + 1, obstacle_part.getX() + 1, OBSTACLE);
    }
}

void Display::printBorders(int x, int y) {
    for (int i = 0; i < x + 2; i++) {
        mvaddch(0, i, GENERIC_BORDER);
        mvaddch(y + 1, i, GENERIC_BORDER);
    }
    for (int j = 0; j < y + 2; j++) {
        mvaddch(j, 0, GENERIC_BORDER);
        mvaddch(j, x + 1, GENERIC_BORDER);
    }
}

void Display::display(const Map &map, const UI &) {
    wclear(this->window);
//    wborder(this->window, LEFT_BORDER, RIGHT_BORDER, UP_BORDER, DOWN_BORDER,
  //          NW_CORNER_BORDER, NE_CORNER_BORDER, SW_CORNER_BORDER, SE_CORNER_BORDER);
    printBorders(this->xSize, this->ySize);
    printSnake(map.getSnake());
    printObstacles(map.getObstacles());
    printFruit(map.getFruit());
    refresh();
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */
const char* Display::UnableToDeleteWindowException::what() const throw(){
    return "Unable to delete nCurses window";
}

const char* Display::BrokenSnakeException::what() const throw(){
    return "Snake is broken";
}