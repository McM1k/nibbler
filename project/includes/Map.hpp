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

    std::ostream &operator<<(std::ostream &o);

    const std::list<Bloc *> getObstacles() const;
    const Bloc getFruit() const;
    const std::list<Bloc *> getSnake() const;
    int getXSize() const;
    int getYSize() const;

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

    void setObstacles(const std::list<Bloc *> &obstacles);

    void setFruit(const Bloc &fruit);

    void setSnake(const std::list<Bloc *> &snake);

    int const xSize{};
    int const ySize{};
    std::list<Bloc *>           obstacles;
    std::list<Bloc *>           snake;
    Bloc fruit;
    static int minObstacles;
};



#endif