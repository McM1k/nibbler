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

# include <iostream>
#include "../includes/LibLoader.hpp"
#include "../includes/IInputs.hpp"

int main() {
    LibLoader libLoader(LibLoader::eLibs::ncursesLib);

    try {
        libLoader.loadFunction<IInputs *(*)()>("newInputs");
    } catch (LibLoader::DLExceptions const &e) {
        std::cout << e.what() << std::endl;
    }
    return 1;
}