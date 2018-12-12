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

#include "../includes/IInput.hpp"
#include "../includes/IEntity.hpp"
#include <iostream>
#include <dlfcn.h>

typedef IEntity *(*ptr_newDisplay)(int, int);

ptr_newDisplay handleDisplay(){
    ptr_newDisplay  ptr;
    void            *dl_handle;

    dl_handle = dlopen("libs/libncurses.so", RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handle){
        std::cerr << "Error : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }

    ptr = (ptr_newDisplay)(dlsym(dl_handle, "newDisplay"));
    if (!ptr){
        std::cerr << "Error : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }

    dlclose(dl_handle);
    return ptr;
}

int main() {
    ptr_newDisplay newDisplay = handleDisplay();
    IEntity *display = newDisplay(10, 10);
    auto ui = new UI();
    auto map = new Map(10, 10);
    auto snake = new std::list<Bloc *>();
    snake->push_back(new Bloc(1,1));
    snake->push_back(new Bloc(1,2));
    snake->push_back(new Bloc(1,3));
    snake->push_back(new Bloc(2,3));
    map->setSnake(*snake);
    auto obstacles = new std::list<Bloc *>();
    obstacles->push_back(new Bloc(5,5));
    obstacles->push_back(new Bloc(5,6));
    obstacles->push_back(new Bloc(6,5));
    obstacles->push_back(new Bloc(6,6));
    map->setObstacles(*obstacles);
    map->setFruit(new Bloc(9,9));

    display->display(*map, *ui);
    return 1;
}