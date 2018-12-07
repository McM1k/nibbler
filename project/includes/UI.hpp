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

class UI {
public:
    UI();
    UI(int);
    UI(UI const & src);
    virtual ~UI();
    
    UI & operator=(UI const &);
private:
    int score;
    GameState

};

std::ostream & operator<<(std::ostream & o, UI const & i); 



#endif
