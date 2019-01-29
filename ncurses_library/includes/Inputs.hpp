/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inputs.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:49:37 by gboudrie          #+#    #+#             */
/*   Updated: 2019/01/18 15:49:37 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_HPP
# define INPUTS_HPP

# include <iostream>
# include <ncurses.h>
#include "../../project/includes/eInputs.hpp"

class Inputs{
public:
    Inputs() = default;
    Inputs(WINDOW *_window);
    virtual ~Inputs() = default;
    Inputs(Inputs const &src) = default;
    Inputs &operator=(Inputs const &rhs) = default;

    eInputs getInput() const ;

private:
    WINDOW *window;
};


#endif