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
# include "IEntity.hpp"
# include "IInputs.hpp"
# include "LibLoader.hpp"
# include "eSharedLibs.hpp"
# include "eInputs.hpp"


class GameManager {
public:
    GameManager() = delete;
    GameManager(GameManager const &src) = default;
    virtual ~GameManager() = default;
    GameManager &operator=(GameManager const &rhs) = default;
    GameManager(int x, int y);

    eGameState getState() const;


    void update();
    void render();
    void changeLib(eSharedLibs lib);
    void instantiateFromLib(eSharedLibs lib);
    void freeLib();
    void loopGame();

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
    Map::direction                          intended_direction;
    std::map<eInputs, ft_input>             map_inputs;
    std::map<eGameState, ft_state>          map_states;
    LibLoader                               *libLoader;
    eGameState                              state;
    IEntity                                 *display;
    IInputs                                 *input;
    Map                                     map;
    UI                                      ui;
    std::chrono::duration<int,std::milli>   ms_per_frame;

};


#endif