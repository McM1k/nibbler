/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:09:22 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/18 14:09:22 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IENTITY_HPP
# define IENTITY_HPP

#  include <iostream>
#  include "Map.hpp"
#  include "UI.hpp"

class IEntity {
public:
    virtual void display(Map const &map, UI const &gameInfo) = 0;
};

#endif