/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:35:14 by vroussea          #+#    #+#             */
/*   Updated: 2018/12/07 15:35:14 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_UI_HPP
#define NIBBLER_UI_HPP

#include <iostream>
#include "eGameState.hpp"
#include "exceptions/UIExceptions.hpp"

class UI {
public:
    UI();

    virtual ~UI() = default;

    int getScore() const;

    void setScore(int score);

    void addScore(int scoreToADd);

    const eGameState &getGameState() const;

    void setGameState(const eGameState &gameState);

private:
    UI(UI const &src) = default;

    UI &operator=(UI const &) = default;

    int score;
    eGameState gameState;

};

std::ostream & operator<<(std::ostream & o, UI const & i); 



#endif
