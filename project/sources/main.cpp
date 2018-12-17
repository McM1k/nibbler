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

#include <dlfcn.h>
#include "../includes/IInput.hpp"
#include "../includes/IEntity.hpp"

typedef IEntity *(*ptr_newDisplay)(int, int);

ptr_newDisplay handleDisplay() {
    ptr_newDisplay ptr;
    void *dl_handle;

    dl_handle = dlopen("libs/libncurses.so", RTLD_NOW | RTLD_LOCAL);
    if (!dl_handle) {
        std::cerr << "Error : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }

    ptr = reinterpret_cast<ptr_newDisplay>(dlsym(dl_handle, "newDisplay"));
    if (!ptr) {
        std::cerr << "Error : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }

    //dlclose(dl_handle);
    return ptr;
}

int main() {
    std::cout << "1" << std::endl;
    ptr_newDisplay newDisplay = handleDisplay();
    std::cout << "2" << std::endl;
    IEntity *display = newDisplay(10, 10);
    std::cout << "3" << std::endl;
    auto ui = new UI();
    std::cout << "4" << std::endl;
    auto map = new Map(10, 10);
    std::cout << "5" << std::endl;
    auto snake = new std::list<Bloc *>();
    snake->push_back(new Bloc(1, 1));
    snake->push_back(new Bloc(1, 2));
    snake->push_back(new Bloc(1, 3));
    snake->push_back(new Bloc(2, 3));
    map->setSnake(*snake);
    auto obstacles = new std::list<Bloc *>();
    obstacles->push_back(new Bloc(5, 5));
    obstacles->push_back(new Bloc(5, 6));
    obstacles->push_back(new Bloc(6, 5));
    obstacles->push_back(new Bloc(6, 6));
    map->setObstacles(*obstacles);
    map->setFruit(new Bloc(9, 9));

    while (newDisplay) {
        display->display(*map, *ui);
    }
    return 1;
}