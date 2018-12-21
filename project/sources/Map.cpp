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

void Map::spawnSnake() {
    std::list<Bloc *> newSnake;
    newSnake.push_back(new Bloc(3,6));
    newSnake.push_back(new Bloc(3,5));
    newSnake.push_back(new Bloc(3,4));

    this->snake = newSnake;
}

void Map::spawnFruit() {
    int x = -1, y = -1;
    std::random_device generator;
    auto snake = this->snake;
//    auto obstacles = map.getObstacles();

    while (x == -1 || y == -1){
        x = (generator())%(this->xSize);
        y = (generator())%(this->ySize);

        for (auto part : snake) {
            if (part->getX() == x && part->getY() == y)
                x = y = -1;
        }
//        for (auto part : obstacles) {
//            if (part->getX() == x && part->getY() == y)
//                x = y = -1;
//        }
    }
    this->fruit = Bloc(x, y);
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