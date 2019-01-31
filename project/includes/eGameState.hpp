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

inline std::ostream& operator<<(std::ostream &o, eGameState &i) {
    switch (i) {
        case eGameState::Menu :
            o << "menu state" << std::endl;
            break;
        case eGameState::Game :
            o << "game state" << std::endl;
            break;
        case eGameState::Pause :
            o << "pause state" << std::endl;
            break;
        case eGameState::GameOver :
            o << "gameOver state" << std::endl;
            break;
        case eGameState::Quit :
            o << "quit state" << std::endl;
            break;
    }
    return o;
}

#endif