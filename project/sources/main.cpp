/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:30:14 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/07 15:30:14 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/GameManager.hpp"

int main(int ac, char **av) {
    if (ac != 3)
        return 1;
    try {
        auto x = std::stoi(av[1]);
        auto y = std::stoi(av[2]);
        GameManager gameManager(x, y);
    }
    catch (std::invalid_argument &e) {std::cout << e.what() << std::endl;}
    catch (std::exception &e)        {std::cout << e.what() << std::endl;}
    return 0;
}