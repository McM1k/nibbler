/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inputs.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:49:03 by gboudrie          #+#    #+#             */
/*   Updated: 2019/01/18 15:49:03 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Inputs.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Inputs::Inputs(WINDOW *_window) : window(_window){}
/* ******************************* */
/*            Accessors            */
/* ******************************* */

eInputs Inputs::getInput() const {
    switch(wgetch(this->window)) {
        case KEY_EXIT:
            return eInputs::quit;
        case '1':
            return eInputs::lib1;
        case '2':
            return eInputs::lib2;
        case '3':
            return eInputs::lib3;
        case ' ':
            return eInputs::pause;
        case KEY_LEFT:
            return eInputs::left;
        case KEY_RIGHT:
            return eInputs::right;
        case KEY_UP:
            return eInputs::up;
        case KEY_DOWN:
            return eInputs::down;
        default:
            return eInputs::noInput;
    }
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */

/* ******************************* */
/*            Exceptions           */
/* ******************************* */
