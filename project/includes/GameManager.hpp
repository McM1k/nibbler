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
# include <chrono>
# include <thread>
# include <map>
# include "LibLoader.hpp"
# include "eSharedLibs.hpp"
# include "eInputs.hpp"
#include "IGraphics.hpp"
#include "eGameState.hpp"


class GameManager {
public:
    GameManager() = delete;

    GameManager(GameManager const &src) = delete;
    virtual ~GameManager() = default;

    GameManager &operator=(GameManager const &rhs) = delete;
    GameManager(int x, int y);

    eGameState getState() const;


    void update();
    void render();
    void changeLib(eSharedLibs lib);
    void instantiateFromLib(eSharedLibs lib);
    void freeLib();
    void loopGame();
    void newGame();

    void gamePause();
    void gameRun();
    void gameQuit();
    void gameOver();

    void inputQuit();
    void inputLib1();
    void inputLib2();
    void inputLib3();
    void inputPause();
    void inputUp();
    void inputDown();
    void inputLeft();
    void inputRight();
    void inputNo();

    typedef void (GameManager::*ft_input)();
    typedef void (GameManager::*ft_state)();

private:
    int                                     frame_required_for_a_move;
    int                                     current_frame;
    Map::eDirection                         current_direction;
    Map::eDirection                         intended_direction;
    std::map<eInputs, ft_input>             map_inputs;
    std::map<eGameState, ft_state>          map_states;
    LibLoader                               *libLoader;
    eGameState                              state;
    IGraphics                               *graphics;
    Map                                     map;
    UI                                      ui;
    std::chrono::duration<int,std::milli>   ms_per_frame;

};


#endif