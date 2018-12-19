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
GameManager::GameManager(int x, int y) : state(eGameState::Menu), map(x, y) {
    instantiateFromLib(eSharedLibs::ncursesLib);
    spawnSnake();
    spawnFruit();
}

GameManager::~GameManager() {
    freeLib();
}

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

void GameManager::spawnSnake() {
    std::list<Bloc *> newSnake;
    newSnake.push_back(new Bloc(3,6));
    newSnake.push_back(new Bloc(3,5));
    newSnake.push_back(new Bloc(3,4));

    this->map.setSnake(newSnake);
}

void GameManager::spawnFruit() {
    int x = -1, y = -1;
    std::random_device generator;
    auto snake = map.getSnake();
//    auto obstacles = map.getObstacles();

    while (x == -1 || y == -1){
        x = (generator())%(this->map.getXSize());
        y = (generator())%(this->map.getYSize());

        for (auto part : snake) {
            if (part->getX() == x && part->getY() == y)
                x = y = -1;
        }
//        for (auto part : obstacles) {
//            if (part->getX() == x && part->getY() == y)
//                x = y = -1;
//        }
    }
    this->map.setFruit(Bloc(x, y));
}

void GameManager::freeLib() {
    if (this->display)
        this->libLoader->loadFunction<void (*)(IEntity *)>("deleteDisplay")(this->display);
    if (this->inputs)
        this->libLoader->loadFunction < void(*)
    (IInputs *) > ("deleteInputs")(this->inputs);
    delete this->libLoader;
}

void GameManager::instantiateFromLib(eSharedLibs lib) {
    this->libLoader = new LibLoader(lib);
    this->display = this->libLoader->loadFunction<IEntity *(*)(int, int)>("newDisplay")(map.getXSize(), map.getYSize());
    this->inputs = this->libLoader->loadFunction<IInputs *(*)()>("newInputs")();
}

void GameManager::changeLib(eSharedLibs lib) {
    if (lib == libLoader->getLibName())
        return;
    state = eGameState::Pause;
    freeLib();
    instantiateFromLib(lib);
}

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

