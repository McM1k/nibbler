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

class Map {
public:
    Map() = delete;
    Map(int _xSize, int _ySize);
    Map(Map const &src) = default;

    virtual ~Map() = default;

    Map &operator=(Map const &rhs) = delete;

    bool addObstacle(int x, int y);
    std::ostream &operator<<(std::ostream &o);

    const std::list<Bloc *> &getObstacles() const;
    const Bloc *getFruit() const;

    void setObstacles(const std::list<Bloc *> &obstacles);
    void setFruit(Bloc *fruit);

private:

    int const xSize{};
    int const ySize{};
    std::list<Bloc *>           obstacles;
    std::list<Bloc *>           snake;
    Bloc *fruit{};
};



#endif