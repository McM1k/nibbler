/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestA.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:27:24 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/06 15:27:24 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestA.hpp"

/*
 * Constructors
 */

/*
 * Destructors
 */

/*
 * Getters
 */

/*
 * Setters
 */

/*
 * Equals
 */

/*
 * ToString
 */
std::ostream &operator<<(std::ostream &o, TestA const &i) {
    o << "no attributes" << std::endl;
    return o;
}

/*
 * Other
 */
void TestA::printStuff() {
    std::cout << "fiuwbfbjdfb" << std::endl;
}

ITestA *stuffA() {
    return new TestA();
}
/*
 * Exceptions
 */