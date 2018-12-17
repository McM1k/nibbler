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
#include "../includes/LibLoader.hpp"
#include "../includes/IInputs.hpp"

int main() {
    try {
        LibLoader libLoader(eSharedLibs::ncursesLib);

    } catch (LibLoader::DLExceptions const &e) {
        std::cout << e.what() << std::endl;
    }

    //while (newDisplay) {
    //    display->display(*map, *ui);
    //}
    return 1;
}