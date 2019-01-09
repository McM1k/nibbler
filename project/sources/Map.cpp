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
Map::Map(int xSize, int ySize) : xSize(xSize), ySize(ySize), fruit(-1, -1) {}

/*
 * Destructors
 */

/*
 * Getters
 */
std::list<Bloc> Map::getObstacles() const {
    return obstacles;
}

Bloc Map::getFruit() const {
    return fruit;
}

std::list<Bloc> Map::getSnake() const{
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
void Map::setObstacles(std::list<Bloc> obstacles) {
    this->obstacles = obstacles;
}

void Map::setFruit(Bloc fruit) {
    this->fruit = fruit;
}

void Map::setSnake(std::list<Bloc> snake) {
    this->snake = snake;
}

/*
 * Operators
 */
 std::ostream& operator<<(std::ostream &o, Map &i) {
    o << "xSize = " << i.getXSize() << ", ySize = " << i.getYSize();
    for (auto obstacles_part : i.getObstacles()) { o << ", obstacles = " << obstacles_part; }
    for (auto snake_part : i.getSnake()) { o << ", snake = " << snake_part; }
    auto fruit = i.getFruit();
    o << ", fruit = " << fruit << std::endl;
    return o;
}

/*
 * Other
 */

void Map::spawnSnake() {
    std::list<Bloc> newSnake;
    newSnake.emplace_back(3,6);
    newSnake.emplace_back(3,5);
    newSnake.emplace_back(3,4);

    this->snake = newSnake;
}

void Map::spawnFruit() {
    int x = -1, y = -1;
    std::random_device generator;

    while (x == -1 || y == -1) {
        x = (generator())%(this->xSize);
        y = (generator())%(this->ySize);

        for (auto part : this->snake) {
            if (part == Bloc(x, y))
                x = y = -1;
        }
        for (auto part : this->obstacles) {
            if (part == Bloc(x, y))
                x = y = -1;
        }
    }
    this->fruit = Bloc(x, y);
}

bool Map::moveSnake(Map::eDirection dir) {
    auto currHead = this->snake.back();
    auto newHead = Bloc(-1, -1);
    if (dir == Map::eDirection::up)
        newHead = Bloc(currHead.getX(), currHead.getY() - 1);
    else if (dir == Map::eDirection::down)
        newHead = Bloc(currHead.getX(), currHead.getY() + 1);
    else if (dir == Map::eDirection::left)
        newHead = Bloc(currHead.getX() - 1, currHead.getY());
    else if (dir == Map::eDirection::right)
        newHead = Bloc(currHead.getX() + 1, currHead.getY());

    if (newHead.getX() < 0 || newHead.getX() >= this->xSize || newHead.getY() < 0 || newHead.getY() > this->ySize)
        return false;

    for (auto obstacle_part : this->obstacles) {
        if (newHead == obstacle_part)
            return false;
    }

    for (auto snake_part : this->snake) {
        if (newHead == snake_part && !(snake_part == this->snake.front()))
            return false;
    }

    if (newHead == this->fruit)
        this->spawnFruit();
    else
        this->snake.pop_front();

    this->snake.push_back(newHead);
    return true;
}

/*
 * Exceptions
 */