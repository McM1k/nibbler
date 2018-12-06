/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:27:26 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/06 15:27:26 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "IEntity.hpp"
#include <dlfcn.h>
#include <iostream>

void doStuff(void *dl_handle){
    void    (*stuffA_ptr)(void);
    void    (*stuffB_ptr)(void);

    stuffA_ptr = (void (*)(void))(dlsym(dl_handle, "stuffA"));
    if (!stuffA_ptr) {
        std::cerr << "Error : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }

    stuffB_ptr = (void (*)(void))(dlsym(dl_handle, "stuffB"));
    if (!stuffB_ptr) {
        std::cerr << "Error : " << dlerror() << std::endl;
        exit(EXIT_FAILURE);
    }

    stuffA_ptr();
    stuffB_ptr();
}

int main() {
    void    *dl_handle;

    dl_handle = dlopen("libs/lib1.so", RTLD_LAZY | RTLD_LOCAL);
    doStuff(dl_handle);
    dlclose(dl_handle);

    dl_handle = dlopen("libs/lib2.so", RTLD_LAZY | RTLD_LOCAL);
    doStuff(dl_handle);
    dlclose(dl_handle);

    return 1;
}