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
#include "LibLoader.hpp"

class UI {
public:
    UI();

    virtual ~UI() = default;

    int getScore() const;

    void setScore(int score);

    void addScore(int scoreToADd);

    const LibLoader::eGameState &getGameState() const;

    void setGameState(const LibLoader::eGameState &gameState);

    class WrongScoreException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
    UI(UI const &src) = default;

    UI &operator=(UI const &) = default;

    int score;
    LibLoader::eGameState gameState;

};

std::ostream & operator<<(std::ostream & o, UI const & i); 



#endif
