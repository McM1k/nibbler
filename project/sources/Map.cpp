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
    if (xSize < 8 || ySize < 8)
        throw MapTooSmallException();
    spawnSnake();
    spawnObstacles();
    spawnFruit();
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

void Map::setObstacles(const std::list<Bloc *> &_obstacles) {
    for (Bloc *obstacle : _obstacles) {
        if (obstacle->getX() < 0 || obstacle->getY() > xSize ||
            obstacle->getY() < 0 || obstacle->getY() > ySize)
            throw OutOfMapException();
    }
    this->obstacles = _obstacles;
}

void Map::setFruit(const Bloc &_fruit) {
    if (_fruit.getX() < 0 || _fruit.getY() > xSize ||
        _fruit.getY() < 0 || _fruit.getY() > ySize)
        throw OutOfMapException();
    this->fruit = _fruit;
}

void Map::setSnake(const std::list<Bloc *> &_snake) {
    for (Bloc *snakePart : _snake) {
        if (snakePart->getX() < 0 || snakePart->getY() > xSize ||
            snakePart->getY() < 0 || snakePart->getY() > ySize)
            throw OutOfMapException();
    }
    this->snake = _snake;
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

void Map::spawnSnake() {
    std::list<Bloc *> newSnake;
    auto middleX = xSize / 2;
    auto middleY = ySize / 2;

    newSnake.push_back(new Bloc(middleX, middleY - 1));
    newSnake.push_back(new Bloc(middleX, middleY));
    newSnake.push_back(new Bloc(middleX, middleY + 1));
    newSnake.push_back(new Bloc(middleX, middleY + 2));

    setSnake(newSnake);
}

void Map::spawnFruit() {
    auto x = -1, y = -1;
    std::random_device generator;
    auto snake = getSnake();
//    auto obstacles = getObstacles();

    while (x == -1 || y == -1){
        x = generator() % (this->xSize + 1);
        y = generator() % (this->ySize + 1);

        for (auto part : snake) {
            if (part->getX() == x && part->getY() == y)
                x = y = -1;
        }
//        for (auto part : obstacles) {
//            if (part->getX() == x && part->getY() == y)
//                x = y = -1;
//        }
    }
    setFruit(Bloc(x, y));
}

void Map::spawnObstacles() {
    auto maxObstacles = (xSize * ySize) / 64 * minObstacles;
    auto x = -1, y = -1;
    std::random_device generator;

    auto numberOfObstacles = generator() % maxObstacles;

    auto currentObstaclesCount = 0;
    while (currentObstaclesCount <)
        while (x == -1 || y == -1) {
            x = generator() % this->xSize;
            y = generator() % this->ySize;

            auto obstacleSize = generator() % 3 + 1;

            if (x == 0 || y == 0)
                x = y = -1;
            else {

                for (auto part : snake) {
                    if (part->getX() == x && part->getY() == y)
                        x = y = -1;
                }
            }
        }
    setFruit(Bloc(x, y));
}

bool Map::moveSnake(Map::eDirection dir) {
    auto currHead = this->snake.back();
    Bloc *newHead;
    if (dir == Map::eDirection::up)
        newHead = new Bloc(currHead->getX(), currHead->getY() - 1);
    else if (dir == Map::eDirection::down)
        newHead = new Bloc(currHead->getX(), currHead->getY() + 1);
    else if (dir == Map::eDirection::left)
        newHead = new Bloc(currHead->getX() - 1, currHead->getY());
    else if (dir == Map::eDirection::right)
        newHead = new Bloc(currHead->getX() + 1, currHead->getY());


}

/*
 * Exceptions
 */

const char *Map::MapTooSmallException::what() const noexcept {
    return "Map must be at least a 8x8 square.";
}

const char *Map::OutOfMapException::what() const noexcept {
    return "Bloc is out of the map.";
}

int Map::minObstacles = 4;