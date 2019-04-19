/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Displayer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:48:50 by gboudrie          #+#    #+#             */
/*   Updated: 2019/01/18 15:48:50 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Displayer.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Displayer::Displayer(int x, int y) : xSize(x), ySize(y){
    curs_set(0);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_BLUE, COLOR_GREEN);
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
void Displayer::printSnake(std::list<Bloc> snake) {
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

    for (const auto &snake_part : snake) {
        mvaddch(snake_part.getY() + 1, snake_part.getX() + 1, GENERIC_SNAKE_PART);
    }
}

void Displayer::printFruit(Bloc fruit) {
    if (fruit.getX() >= 0 && fruit.getY() >= 0) {
        mvaddch(fruit.getY() + 1, fruit.getX() + 1, FRUIT);
    }
}

void Displayer::printObstacles(std::list<Bloc> obstacles) {
    for (const auto &obstacle_part : obstacles) {
        mvaddch(obstacle_part.getY() + 1, obstacle_part.getX() + 1, OBSTACLE);
    }
}

void Displayer::printBorders() {
    for (int i = 0; i < xSize + 2; i++) {
        mvaddch(0, i, GENERIC_BORDER);
        mvaddch(ySize + 1, i, GENERIC_BORDER);
    }
    for (int j = 0; j < ySize + 2; j++) {
        mvaddch(j, 0, GENERIC_BORDER);
        mvaddch(j, xSize + 1, GENERIC_BORDER);
    }
}

void Displayer::printUI(UI const &gameInfo) {
    std::stringstream stringstream;

    stringstream << static_cast<eGameState>(gameInfo.getGameState());

    mvprintw(ySize + 2, 0, "Game State : %s | Score : %d", stringstream.str().c_str(), gameInfo.getScore());
}

void Displayer::display(const Map &map, const UI &gameInfo) {
    clear();
    //wclear(this->window);
//    wborder(this->window, LEFT_BORDER, RIGHT_BORDER, UP_BORDER, DOWN_BORDER,
  //          NW_CORNER_BORDER, NE_CORNER_BORDER, SW_CORNER_BORDER, SE_CORNER_BORDER);
    attrset(COLOR_PAIR(1));
    printBorders();
    printObstacles(map.getObstacles());
    attrset(COLOR_PAIR(3));
    printSnake(map.getSnake());

    attrset(COLOR_PAIR(2));
    printFruit(map.getFruit());
    printUI(gameInfo);
    attrset(COLOR_PAIR(0));
    //wrefresh(this->window);
    refresh();
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */
const char *Displayer::UnableToDeleteWindowException::what() const noexcept {
    return "Unable to delete nCurses window";
}

const char *Displayer::BrokenSnakeException::what() const noexcept {
    return "Snake is broken";
}