
#include "../includes/GameManager.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
GameManager::GameManager(int x, int y) : map(x, y) {
    map.
}
/* ******************************* */
/*            Accessors            */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
void GameManager::spawnSnake() {
    auto newSnake = new std::list<Bloc *>();
    newSnake->push_back(new Bloc(3,6));
    newSnake->push_back(new Bloc(3,5));
    newSnake->push_back(new Bloc(3,4));

    this->map.setSnake(newSnake);
}

void GameManager::spawnFruit() {
    int x = -1, y = -1;
    std::random_device generator;
    auto snake = map.getSnake();
    auto obstacles = map.getObstacles();

    while (x == -1 || y == -1){
        x = (generator())%(this->map.getX());
        y = (generator())%(this->map.getY());

        for (auto part : snake) {
            if (part->getX() == x && part->getY() == y)
                x = y = -1;
        }
        for (auto part : obstacles) {
            if (part->getX() == x && part->getY() == y)
                x = y = -1;
        }
    }
    this->map.setFruit(new Bloc(x, y));
}

IEntity *GameManager::changeLib(LibLoader::eSharedLib lib) {

}

void GameManager::update() {

}
/* ******************************* */
/*            Exceptions           */
/* ******************************* */

