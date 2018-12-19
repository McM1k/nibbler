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
#include <ncurses.h>
#include "../includes/LibLoader.hpp"
#include "../includes/IInputs.hpp"
#include "../includes/GameManager.hpp"

int main(int argc, const char **argv) {
    std::cout << argc << std::endl;
    if (argc == 3) {
        try {
            GameManager gameManager(std::stoi(argv[1]), std::stoi(argv[2]));
            IInputs *inputs = gameManager.getInputs();

            int c = inputs->getInput();
            while (c != 27) {
                c = inputs->getInput();
            }

        } catch (LibLoader::DLExceptions const &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 1;
}