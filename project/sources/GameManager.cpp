/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:08:47 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/18 14:08:47 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GameManager.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
GameManager::GameManager() : state(eGameState::Menu) {}

/* ******************************* */
/*            Accessors            */
/* ******************************* */
eGameState GameManager::getState() const {
    return state;
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
void GameManager::startGame(int x, int y) {
    this->map = new Map(x, y);
    spawnSnake();
    spawnFruit();
}

void GameManager::spawnSnake() {
    auto newSnake = new std::list<Bloc *>();
    newSnake->push_back(new Bloc(3,6));
    newSnake->push_back(new Bloc(3,5));
    newSnake->push_back(new Bloc(3,4));

    this->map->setSnake(*newSnake);
}

void GameManager::spawnFruit() {
    int x = -1, y = -1;
    std::random_device generator;
    auto snake = map->getSnake();
    auto obstacles = map->getObstacles();

    while (x == -1 || y == -1){
        x = (generator())%(this->map->getXSize());
        y = (generator())%(this->map->getYSize());

        for (auto part : snake) {
            if (part->getX() == x && part->getY() == y)
                x = y = -1;
        }
        for (auto part : obstacles) {
            if (part->getX() == x && part->getY() == y)
                x = y = -1;
        }
    }
    this->map->setFruit(*(new Bloc(x, y)));
}

//IEntity *GameManager::changeLib(eSharedLibs libs) {

//}

void GameManager::update() {
    while (this->getState() == eGameState::Game)
    {
   //     double start = getCurrentTime();
 //       processInput();
        update();
        render();

//        sleep(start + MS_PER_FRAME - getCurrentTime());
    }
}

void GameManager::render() {

}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

