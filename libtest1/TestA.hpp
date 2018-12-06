/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestA.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:27:19 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/06 15:27:19 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTA_HPP
# define TESTA_HPP

# include <iostream>

class TestA{
public:
    TestA(void) = default;
    TestA(TestA const &src) = default;
    virtual ~TestA(void) = default;
    TestA &operator=(TestA const &rhs) = default; //equals

private:

};

extern "C" void stuffA();

std::ostream &operator<<(std::ostream &o, TestA const &i);

#endif