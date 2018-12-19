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
    GameManager(void) = delete;
    GameManager(GameManager const &src) = default;
    virtual ~GameManager(void);
    GameManager &operator=(GameManager const &rhs) = default;
    GameManager(int x, int y);

    eGameState getState() const;

    void spawnFruit();
    void spawnSnake();
//    void spawnObstacle();
    void update();
    void render();
    void changeLib(eSharedLibs lib);
    void instantiateFromLib(eSharedLibs lib);
    void freeLib();

private:
    LibLoader           *libLoader;
    eGameState          state;
    IEntity             *display;
    IInputs             *input;
    Map                 map;
   // UI                  ui; //TODO init

};


#endif