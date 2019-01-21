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

# include "../../project/includes/IInputs.hpp"
# include <iostream>
# include <ncurses.h>

class Inputs : public IInputs {
public:
    Inputs() = default;

    virtual ~Inputs() = default;

    eInputs getInput() const override;

private:
    Inputs(Inputs const &src) = default;

    Inputs &operator=(Inputs const &rhs) = default;

};

extern "C" {
Inputs *newInputs();
void deleteInputs(Inputs *inputs);
}

#endif