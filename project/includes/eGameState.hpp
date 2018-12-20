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

#endif