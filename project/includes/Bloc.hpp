/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bloc.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:03:10 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/07 17:03:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOC_HPP
# define BLOC_HPP

# include <iostream>

class Bloc {
public:
    Bloc(const int x, const int y);
    Bloc(Bloc const &src) = default;
    virtual ~Bloc(void) = default;
    Bloc &operator=(Bloc const &rhs);
    std::ostream &operator<<(std::ostream &o);

    bool operator==(Bloc const &rhs);

    const int getX() const;
    const int getY() const;

private:
    Bloc(void) = default;

    int     x;
    int     y;

};

#endif