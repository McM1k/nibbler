/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:30:08 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/07 15:30:08 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "Bloc.hpp"
# include "ObstaclesFactory.hpp"
# include <list>
# include <iostream>
# include <random>

class Map {
public:
    Map() = delete;
    Map(int _xSize, int _ySize);
    Map(Map const &src) = default;
    virtual ~Map() = default;

    Map &operator=(Map const &rhs) = delete;



    std::list<Bloc> getObstacles() const;
    Bloc getFruit() const;
    std::list<Bloc> getSnake() const;
    int getXSize() const;
    int getYSize() const;

    void setObstacles(const std::list<Bloc> &_obstacles);

    void setFruit(const Bloc &_fruit);

    void setSnake(const std::list<Bloc> &_snake);

    void spawnFruit();
    void spawnSnake();
    void spawnObstacles();

    typedef enum {left, right, up, down} eDirection;
    bool moveSnake(eDirection dir);

    class MapTooSmallException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class OutOfMapException : public std::exception {
    public:
        const char *what() const noexcept override;
    };
private:
    int const           xSize{};
    int const           ySize{};
    std::list<Bloc>     obstacles;
    std::list<Bloc>     snake;
    Bloc                fruit;
    static int minObstacles;
};

std::ostream &operator<<(std::ostream &o, Map &i);

#endif