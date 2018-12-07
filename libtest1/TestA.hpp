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

# include "ITestA.hpp"
# include <iostream>

class TestA : public ITestA{
public:
    TestA(void) = default;
    TestA(TestA const &src) = default;
    virtual ~TestA(void) = default;
    TestA &operator=(TestA const &rhs) = default; //equals
    void printStuff();
private:
    
};

extern "C" ITestA *stuffA();

std::ostream &operator<<(std::ostream &o, TestA const &i);

#endif