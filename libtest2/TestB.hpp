/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestB.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:27:16 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/06 15:27:16 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTB_HPP
# define TESTB_HPP

# include <iostream>

class TestB {
public:
    TestB(void) = default;
    TestB(TestB const &src) = default;
    virtual ~TestB(void) = default;
    TestB &operator=(TestB const &rhs) = default; //equals

private:

};

extern "C" void stuffB();

std::ostream &operator<<(std::ostream &o, TestB const &i);

#endif