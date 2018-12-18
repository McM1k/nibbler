/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:08:35 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/18 14:08:35 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEMANAGER_HPP
# define GAMEMANAGER_HPP

# include <iostream>
# include <random>
# include "IEntity.hpp"
# include "IInputs.hpp"
# include "LibLoader.hpp"
# include "eSharedLibs.hpp"


class GameManager {
public:
    GameManager(void);
    GameManager(GameManager const &src) = default;
    virtual ~GameManager(void){};
    GameManager &operator=(GameManager const &rhs) = default;


    eGameState getState() const;

    void startGame(int x, int y);
    void spawnFruit();
    void spawnSnake();
//    void spawnObstacle();
    void update();
    void render();
   // IEntity *changeLib(eSharedLibs lib);

private:
    eGameState          state; //TODO init
  //  IEntity             *display; //TODO init
   // IInputs             *input; //TODO init
    Map                 *map;
   // UI                  *ui; //TODO init

};


#endif