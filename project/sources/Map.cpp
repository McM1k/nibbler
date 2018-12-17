/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:30:06 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/07 15:30:06 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Map.hpp"

/*
 * Constructors
 */
Map::Map(int xSize, int ySize) : xSize(xSize), ySize(ySize), obstacles(), snake() {
    fruit = nullptr;
}

/*
 * Destructors
 */

/*
 * Getters
 */
const std::list<Bloc *> &Map::getObstacles() const {
    return obstacles;
}

const Bloc *Map::getFruit() const {
    return fruit;
}

const std::list<Bloc *> &Map::getSnake() const{
    return snake;
}

/*
 * Setters
 */
void Map::setObstacles(std::list<Bloc *> &obstacles) {
    this->obstacles = obstacles;
}

void Map::setFruit(Bloc *fruit) {
    this->fruit = fruit;
}

void Map::setSnake(std::list<Bloc *> &snake) {
    Map::snake = snake;
}

/*
 * Operators
 */
 std::ostream& Map::operator<<(std::ostream &o) {
    o << "xSize = " << this->xSize << ", ySize = " << this->ySize;
    for (Bloc *obstacles_part : this->obstacles) { o << ", obstacles = " << obstacles_part; }
    for (Bloc *snake_part : this->snake) { o << ", snake = " << snake_part; }
    o << ", fruit = " << &(this->fruit) << std::endl;
    return o;
}

/*
 * Other
 */
bool Map::addObstacle(int x, int y) {
    if (x < 0 || x >= this->xSize || y < 0 || y >= this->ySize)
        return false;
    auto *newObstacle = new Bloc(x, y);

    for (Bloc *snake_part : this->snake){
        if (*snake_part == *newObstacle)
            return false;
    }

    for (Bloc *obstacles_part : this->snake){
        if (*obstacles_part == *newObstacle)
            return false;
    }

    if (this->fruit == newObstacle)
        return false;

    this->obstacles.push_front(newObstacle);
    return true;
}

/*
 * Exceptions
 */