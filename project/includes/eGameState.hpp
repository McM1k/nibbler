/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eGameState.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:09:06 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/18 14:09:06 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EGAMESTATE_HPP
# define EGAMESTATE_HPP

typedef enum {
    Menu,
    Game,
    Pause,
    GameOver,
    Quit
} eGameState;

inline std::ostream &operator<<(std::ostream &o, eGameState const &i) {
    switch (i) {
        case eGameState::Menu :
            o << "menu";
            break;
        case eGameState::Game :
            o << "game";
            break;
        case eGameState::Pause :
            o << "pause";
            break;
        case eGameState::GameOver :
            o << "gameOver";
            break;
        case eGameState::Quit :
            o << "quit";
            break;
    }
    return o;
}

#endif