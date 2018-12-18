/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IInputs.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:09:26 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/18 14:09:26 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IINPUT_HPP
# define IINPUT_HPP

# include <iostream>

class IInputs {
public:
    virtual int getInput() const = 0;
};

#endif