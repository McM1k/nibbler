/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bloc.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:03:08 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/07 17:03:08 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bloc.hpp"

/*
 * Constructors
 */
Bloc::Bloc(const int x, const int y) : x(x), y(y) {}

/*
 * Destructors
 */

/*
 * Getters
 */
int Bloc::getX() const {
    return x;
}

int Bloc::getY() const {
    return y;
}

/*
 * Setters
 */

/*
 * Operators
 */
Bloc& Bloc::operator=(Bloc const &rhs) {
    if (this != &rhs) {
        this->x = rhs.getX();
        this->y = rhs.getY();
    }
    return *this;
}

bool Bloc::operator==(Bloc const &rhs) {
    return this->x == rhs.getX() && this->y == rhs.getY();
}

std::ostream& Bloc::operator<<(std::ostream &o) {
    o << "x = " << this->x << ", y = " << this->y << std::endl;
    return o;
}

/*
 * Other
 */

/*
 * Exceptions
 */