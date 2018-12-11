/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UIExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:09:20 by vroussea          #+#    #+#             */
/*   Updated: 2018/12/07 16:09:20 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_UIExceptions_HPP
#define NIBBLER_UIExceptions_HPP


#include <iostream>

class UIExceptions {
public:
    class WrongScoreException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
    UIExceptions() = default;

    UIExceptions(UIExceptions const &src) = default;

    virtual ~UIExceptions() = default;

    UIExceptions &operator=(UIExceptions const &) = default;
};

std::ostream &operator<<(std::ostream &o, UIExceptions const &i);


#endif
