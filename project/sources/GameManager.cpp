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

#include <zconf.h>
#include "../includes/GameManager.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
GameManager::GameManager(int x, int y) : state(eGameState::Menu), map(x, y) {
    instantiateFromLib(eSharedLibs::ncursesLib);
    spawnSnake();
    spawnFruit();
    UI ui;


    const double maxFPS = 60.0;
    const double maxPeriod = 1.0 / maxFPS;

// approx ~ 16.666 ms

    bool running = true;
    clock_t lastTime = 0;

    while (running) {
        clock_t time = clock();
        clock_t deltaTime = time - lastTime;

        if (deltaTime >= maxPeriod) {
            lastTime = time;
            display->display(map, ui);
        }
    }

    clock_t current_ticks, delta_ticks;
    clock_t fps = 0;
    while (true)// your main loop. could also be the idle() function in glut or whatever
    {
        current_ticks = clock();

        display->display(map, ui);

        delta_ticks = clock() - current_ticks; //the time, in ms, that took to render the scene
        if (delta_ticks > 0)
            fps = CLOCKS_PER_SEC / delta_ticks;
        std::cout << fps << std::endl;
    }
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

