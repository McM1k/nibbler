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
    Bloc(int x, int y);
    Bloc(Bloc const &src) = default;

    virtual ~Bloc() = default;
    Bloc &operator=(Bloc const &rhs);
    std::ostream &operator<<(std::ostream &o);

    bool operator==(Bloc const &rhs);

    int getX() const;
    int getY() const;

private:
    Bloc() = default;

    int x{};
    int y{};

};

#endif