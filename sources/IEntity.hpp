/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:27:05 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/06 15:27:05 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IENTITY_HPP
# define IENTITY_HPP

# include <iostream>

class IEntity {
public:
    virtual void stuffA() = 0;
    virtual void stuffB() = 0;

    virtual ~IEntity() = default;
};
#endif