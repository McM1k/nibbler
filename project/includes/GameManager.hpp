
#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

# include <iostream>
# include <random>
# include "IEntity.hpp"
# include "Map.hpp"
# include "LibLoader.hpp"


class GameManager {
public:
    GameManager(void) = default;
    GameManager(GameManager const &src) = default;
    virtual ~GameManager(void) = default;
    GameManager &operator=(GameManager const &rhs) = default;

    GameManager(int x, int y);

    void spawnFruit();
    void spawnSnake();
    void spawnObstacle()
    void update();
    IEntity *changeLib(LibLoader::eSharedLib lib);

    typedef enum {Menu, Game, Pause, GameOver} eGameState;
private:
    IEntity             *display;
    Map                 &map;
};


#endif