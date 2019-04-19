/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:35:11 by vroussea          #+#    #+#             */
/*   Updated: 2018/12/07 15:35:11 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/UI.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

UI::UI() : score(0), gameState(eGameState::Game) {

}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */
UI& UI::operator=(UI const &rhs) {
    this->score = rhs.getScore();
    this->gameState = rhs.getGameState();

    return *this;
}

std::ostream &operator<<(std::ostream &o, UI const &instance) {
    o << "UI :" << std::endl;
    o << "Score :" << instance.getScore() << std::endl;
    o << "State of the game :" << instance.getGameState();

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

void UI::addScore(int scoreToADd) {
    if (scoreToADd >= 0)
        score += scoreToADd;
    else
        throw UI::WrongScoreException();
}


/* ******************************* */
/*            Accessors            */
/* ******************************* */

int UI::getScore() const {
    return score;
}

void UI::setScore(int score) {
    if (score < 0)
        throw UI::WrongScoreException();
    this->score = score;
}

const eGameState &UI::getGameState() const {
    return gameState;
}

void UI::setGameState(const eGameState &gameState) {
    this->gameState = gameState;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */
const char *UI::WrongScoreException::what() const noexcept {
    return "You have to add positive value to score.";
}

