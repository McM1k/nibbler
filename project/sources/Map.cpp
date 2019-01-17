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

void Map::setObstacles(const std::list<Bloc> &_obstacles) {
    for (auto const &obstacle : _obstacles) {
        if (obstacle.getX() < 0 || obstacle.getY() > xSize ||
            obstacle.getY() < 0 || obstacle.getY() > ySize)
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

void Map::setSnake(const std::list<Bloc> &_snake) {
    for (auto const &snakePart : _snake) {
        if (snakePart.getX() < 0 || snakePart.getY() > xSize ||
            snakePart.getY() < 0 || snakePart.getY() > ySize)
            throw OutOfMapException();
    }
    this->snake = _snake;
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
    auto middleX = xSize / 2;
    auto middleY = ySize / 2;

    newSnake.emplace_back(Bloc(middleX, middleY - 1));
    newSnake.emplace_back(Bloc(middleX, middleY));
    newSnake.emplace_back(Bloc(middleX, middleY + 1));
    newSnake.emplace_back(Bloc(middleX, middleY + 2));

    setSnake(newSnake);
}

void Map::spawnFruit() {
    auto x = -1, y = -1;
    std::random_device generator;

    while (x == -1 || y == -1) {
        x = generator() % (this->xSize + 1);
        y = generator() % (this->ySize + 1);

        for (auto part : this->snake) {
            if (part == Bloc(x, y))
                x = y = -1;
        }
        for (auto part : this->obstacles) {
            if (part == Bloc(x, y))
                x = y = -1;
        }
    }
    setFruit(Bloc(x, y));
}

void Map::spawnObstacles() {
    auto maxObstacles = (xSize * ySize) / 64 * minObstacles;
    std::random_device generator;

    auto numberOfObstacles = generator() % maxObstacles;

    std::cout << "number of obstacles : " << numberOfObstacles << std::endl;

    ObstaclesFactory obstaclesFactory;

    obstaclesFactory.generateAllObstacles(obstacles, numberOfObstacles, xSize, ySize, snake, 0);
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

    for (auto const &obstacle_part : this->obstacles) {
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

const char *Map::MapTooSmallException::what() const noexcept {
    return "Map must be at least a 8x8 square.";
}

const char *Map::OutOfMapException::what() const noexcept {
    return "Bloc is out of the map.";
}

int Map::minObstacles = 4;