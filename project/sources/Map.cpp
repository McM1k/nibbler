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
Map::Map(int xSize, int ySize) : xSize(xSize), ySize(ySize), fruit(-1, -1) {

}

/*
 * Destructors
 */

/*
 * Getters
 */
const std::list<Bloc *> Map::getObstacles() const {
    return obstacles;
}

const Bloc Map::getFruit() const {
    return fruit;
}

const std::list<Bloc *> Map::getSnake() const{
    return snake;
}

int Map::getXSize() const {
    return xSize;
}

int Map::getYSize() const {
    return ySize;
}

/*
 * Setters
 */
void Map::setObstacles(std::list<Bloc *> obstacles) {
    this->obstacles = obstacles;
}

void Map::setFruit(Bloc fruit) {
    this->fruit = fruit;
}

void Map::setSnake(std::list<Bloc *> snake) {
    this->snake = snake;
}

/*
 * Operators
 */
 std::ostream& Map::operator<<(std::ostream &o) {
    o << "xSize = " << this->xSize << ", ySize = " << this->ySize;
    for (auto obstacles_part : this->obstacles) { o << ", obstacles = " << obstacles_part; }
    for (auto snake_part : this->snake) { o << ", snake = " << snake_part; }
    o << ", fruit = " << &(this->fruit) << std::endl;
    return o;
}

/*
 * Other
 */

/*
 * Exceptions
 */