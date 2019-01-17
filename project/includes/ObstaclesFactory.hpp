
#ifndef NIBBLER_OBSTACLESFACTORY_HPP
#define NIBBLER_OBSTACLESFACTORY_HPP


# include <iostream>
# include <list>
# include "Bloc.hpp"
# include <random>
# include <array>

class ObstaclesFactory {
public:

    typedef void (ObstaclesFactory::*PointerToObstacleFunction)(std::list<Bloc> &obstacles,
                                                                int sizeX,
                                                                int sizeY,
                                                                std::list<Bloc> &snake);

    ObstaclesFactory();

    ObstaclesFactory(ObstaclesFactory const &src) = delete;

    virtual ~ObstaclesFactory() = default;

    ObstaclesFactory &operator=(ObstaclesFactory const &) = delete;

    void generateAllObstacles(
            std::list<Bloc> &obstacles,
            unsigned int obstaclesToAdd,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake,
            int numberOfTimeItTried);

    class CannotPlaceObstacleHereException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
    void generateOneObstacle(
            std::list<Bloc> &obstacles,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake);

    void generateSimpleObstacle(
            std::list<Bloc> &obstacles,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake);

    void generateLeftUpCornerObstacle(
            std::list<Bloc> &obstacles,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake);

    void generateLeftDownCornerObstacle(
            std::list<Bloc> &obstacles,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake);

    void generateRightUpCornerObstacle(
            std::list<Bloc> &obstacles,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake);

    void generateRightDownCornerObstacle(
            std::list<Bloc> &obstacles,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake);

    void generateHorizontalBarObstacle(
            std::list<Bloc> &obstacles,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake);

    void generateVerticalBarObstacle(
            std::list<Bloc> &obstacles,
            int sizeX,
            int sizeY,
            std::list<Bloc> &snake);

    bool checkPlaceIsEmpty(int x, int y, int sizeX, int sizeY,
                           std::list<Bloc> &snake,
                           std::list<Bloc> &obstacles);

    bool checkOneSquare(int x, int y, int sizeX, int sizeY,
                        std::list<Bloc> &snake,
                        std::list<Bloc> &obstacles);

    unsigned int const numberOfDifferentObstacles;
    std::random_device generator;
    std::array<ObstaclesFactory::PointerToObstacleFunction, 7> obstaclesTypes;
};

std::ostream &operator<<(std::ostream &o, ObstaclesFactory const &i);


#endif
