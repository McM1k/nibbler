
#include "../includes/ObstaclesFactory.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

ObstaclesFactory::ObstaclesFactory() : numberOfDifferentObstacles(7) {
    obstaclesTypes.at(0) = &ObstaclesFactory::generateSimpleObstacle;
    obstaclesTypes.at(1) = &ObstaclesFactory::generateLeftUpCornerObstacle;
    obstaclesTypes.at(2) = &ObstaclesFactory::generateLeftDownCornerObstacle;
    obstaclesTypes.at(3) = &ObstaclesFactory::generateRightUpCornerObstacle;
    obstaclesTypes.at(4) = &ObstaclesFactory::generateRightDownCornerObstacle;
    obstaclesTypes.at(5) = &ObstaclesFactory::generateHorizontalBarObstacle;
    obstaclesTypes.at(6) = &ObstaclesFactory::generateVerticalBarObstacle;
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */

void ObstaclesFactory::generateAllObstacles(
        std::list<Bloc> &obstacles,
        unsigned int obstaclesToAdd,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake,
        int numberOfTimeItTried) {
    if (numberOfTimeItTried > 600) {
        std::cerr << "Cannot place all obstacles" << std::endl;
        return;
    }
    if (obstaclesToAdd > 0) {
        try {
            generateOneObstacle(obstacles, sizeX, sizeY, snake);
            generateAllObstacles(obstacles, --obstaclesToAdd, sizeX, sizeY, snake, ++numberOfTimeItTried);
        } catch (CannotPlaceObstacleHereException const &e) {
            std::cerr << e.what() << std::endl;
            generateAllObstacles(obstacles, obstaclesToAdd, sizeX, sizeY, snake, ++numberOfTimeItTried);
        }
        catch (std::exception const &e) {
            std::cerr << "Something has gone unexpectedly wrong : " << e.what() << std::endl;
            generateAllObstacles(obstacles, obstaclesToAdd, sizeX, sizeY, snake, ++numberOfTimeItTried);
        }
    }
}

void ObstaclesFactory::generateOneObstacle(
        std::list<Bloc> &obstacles,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake) {
    auto whichObstacleToGenerate = generator() % numberOfDifferentObstacles;

    (this->*obstaclesTypes[whichObstacleToGenerate])(obstacles, sizeX, sizeY, snake);
}

void ObstaclesFactory::generateSimpleObstacle(
        std::list<Bloc> &obstacles,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake) {
    int x = generator() % sizeX;
    int y = generator() % sizeY;

    if (checkPlaceIsFine(x, y, sizeX, sizeY, snake, obstacles)) {
        obstacles.emplace_back(Bloc(x, y));
    } else
        throw CannotPlaceObstacleHereException();
}

void ObstaclesFactory::generateLeftUpCornerObstacle(
        std::list<Bloc> &obstacles,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake) {
    int x = generator() % sizeX;
    int y = generator() % sizeY;
    int x1 = x + 1;
    int y1 = y - 1;

    if (checkPlaceIsFine(x, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x1, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x, y1, sizeX, sizeY, snake, obstacles)) {
        obstacles.emplace_back(Bloc(x, y));
        obstacles.emplace_back(Bloc(x1, y));
        obstacles.emplace_back(Bloc(x, y1));
    } else
        throw CannotPlaceObstacleHereException();
}

void ObstaclesFactory::generateLeftDownCornerObstacle(
        std::list<Bloc> &obstacles,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake) {
    int x = generator() % sizeX;
    int y = generator() % sizeY;
    int x1 = x + 1;
    int y1 = y + 1;

    if (checkPlaceIsFine(x, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x1, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x, y1, sizeX, sizeY, snake, obstacles)) {
        obstacles.emplace_back(Bloc(x, y));
        obstacles.emplace_back(Bloc(x1, y));
        obstacles.emplace_back(Bloc(x, y1));
    } else
        throw CannotPlaceObstacleHereException();
}

void ObstaclesFactory::generateRightUpCornerObstacle(
        std::list<Bloc> &obstacles,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake) {
    int x = generator() % sizeX;
    int y = generator() % sizeY;
    int x1 = x - 1;
    int y1 = y - 1;

    if (checkPlaceIsFine(x, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x1, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x, y1, sizeX, sizeY, snake, obstacles)) {
        obstacles.emplace_back(Bloc(x, y));
        obstacles.emplace_back(Bloc(x1, y));
        obstacles.emplace_back(Bloc(x, y1));
    } else
        throw CannotPlaceObstacleHereException();
}

void ObstaclesFactory::generateRightDownCornerObstacle(
        std::list<Bloc> &obstacles,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake) {
    int x = generator() % sizeX;
    int y = generator() % sizeY;
    int x1 = x - 1;
    int y1 = y + 1;

    if (checkPlaceIsFine(x, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x1, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x, y1, sizeX, sizeY, snake, obstacles)) {
        obstacles.emplace_back(Bloc(x, y));
        obstacles.emplace_back(Bloc(x1, y));
        obstacles.emplace_back(Bloc(x, y1));
    } else
        throw CannotPlaceObstacleHereException();
}

void ObstaclesFactory::generateHorizontalBarObstacle(
        std::list<Bloc> &obstacles,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake) {
    int x = generator() % sizeX;
    int y = generator() % sizeY;
    int x1 = x + 1;

    if (checkPlaceIsFine(x, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(x1, y, sizeX, sizeY, snake, obstacles)) {
        obstacles.emplace_back(Bloc(x, y));
        obstacles.emplace_back(Bloc(x1, y));
    } else
        throw CannotPlaceObstacleHereException();
}

void ObstaclesFactory::generateVerticalBarObstacle(
        std::list<Bloc> &obstacles,
        int sizeX,
        int sizeY,
        std::list<Bloc> &snake) {
    int x = generator() % sizeX;
    int y = generator() % sizeY;
    int y1 = y + 1;

    if (checkPlaceIsFine(x, y, sizeX, sizeY, snake, obstacles) &&
        checkPlaceIsFine(y1, y, sizeX, sizeY, snake, obstacles)) {
        obstacles.emplace_back(Bloc(x, y));
        obstacles.emplace_back(Bloc(y1, y));
    } else
        throw CannotPlaceObstacleHereException();
}

bool ObstaclesFactory::checkPlaceIsFine(int x, int y, int sizeX, int sizeY,
                                        std::list<Bloc> &snake,
                                        std::list<Bloc> &obstacles) {
    return !(!checkOneSquareIsNotOnBorder(x, y, sizeX, sizeY) ||
             !checkOneSquareIsEmpty(x, y, snake, obstacles) ||
             !checkOneSquareIsEmpty(x + 1, y, snake, obstacles) ||
             !checkOneSquareIsEmpty(x - 1, y, snake, obstacles) ||
             !checkOneSquareIsEmpty(x, y + 1, snake, obstacles) ||
             !checkOneSquareIsEmpty(x, y - 1, snake, obstacles) ||
             !checkOneSquareIsEmpty(x - 1, y - 1, snake, obstacles) ||
             !checkOneSquareIsEmpty(x + 1, y - 1, snake, obstacles) ||
             !checkOneSquareIsEmpty(x - 1, y + 1, snake, obstacles) ||
             !checkOneSquareIsEmpty(x + 1, y + 1, snake, obstacles));

}

bool ObstaclesFactory::checkOneSquareIsEmpty(int x, int y, std::list<Bloc> &snake, std::list<Bloc> &obstacles) {
    for (auto part : snake) {
        if (part == Bloc(x, y))
            return false;
    }

    for (auto part : obstacles) {
        if (part == Bloc(x, y))
            return false;
    }

    return true;
}

bool ObstaclesFactory::checkOneSquareIsNotOnBorder(int x, int y, int sizeX, int sizeY) {
    return !(x <= 0 || x >= sizeX - 1 || y <= 0 || y >= sizeY - 1);
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */


/* ******************************* */
/*            Exceptions           */
/* ******************************* */

const char *ObstaclesFactory::CannotPlaceObstacleHereException::what() const noexcept {
    return "Obstacle cannot be placed here.";
}