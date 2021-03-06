/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LibLoader.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:08:42 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/18 14:08:42 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LibLoader.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

LibLoader::LibLoader(eSharedLibs _libName) : libName(_libName), LIBSNUMBER(4) {
    char *libs[LIBSNUMBER];

    libs[eSharedLibs::ncursesLib] = const_cast<char *>("libs/libncurses.so");
    libs[eSharedLibs::mlxLib] = const_cast<char *>("libs/libmlx.so");

    dl_handle = dlopen(libs[this->libName], RTLD_NOW | RTLD_LOCAL);

    if (!dl_handle) { throw DLExceptions(); }
}

LibLoader::~LibLoader() {
    dlclose(dl_handle);
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

std::ostream &operator<<(std::ostream &o, LibLoader const &instance) {
    o << "LibName : " << instance.getLibs()[instance.getLibName()];

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

/* ******************************* */
/*            Accessors            */
/* ******************************* */

eSharedLibs LibLoader::getLibName() const {
    return this->libName;
}

char *const *LibLoader::getLibs() const {
    return this->libs;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

const char *LibLoader::DLExceptions::what() const noexcept {
    return dlerror();
}