/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:18:12 by gboudrie          #+#    #+#             */
/*   Updated: 2019/01/28 16:18:12 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_IGRAPHICS_HPP
#define NIBBLER_IGRAPHICS_HPP

#include "Map.hpp"
#include "UI.hpp"
#include "eInputs.hpp"

class IGraphics {
public :
    virtual void display(Map const &map, UI const &gameInfo) = 0;
    virtual eInputs getInput() const = 0;
};

#endif
