/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LibLoader.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:08:52 by gboudrie          #+#    #+#             */
/*   Updated: 2018/12/18 14:08:52 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_LIBLOADER_HPP
#define NIBBLER_LIBLOADER_HPP

#include <dlfcn.h>
#include <iostream>
#include "eSharedLibs.hpp"

class LibLoader {
public:

    LibLoader() = delete;

    explicit LibLoader(eSharedLibs _libName);

    LibLoader(LibLoader const &src) = delete;

    virtual ~LibLoader();

    LibLoader &operator=(LibLoader const &) = delete;

    eSharedLibs getLibName() const;

    char *const *getLibs() const;

    class DLExceptions : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    template<typename T>
    T loadFunction(const char *functionName) const {
        T function_ptr;

        function_ptr = reinterpret_cast<T>(dlsym(dl_handle, functionName));
        if (!function_ptr)
            throw DLExceptions();
        return function_ptr;
    }

private:
    void *dl_handle;
    char *libs[3];
    const eSharedLibs libName;
    const int LIBSNUMBER;

};

std::ostream &operator<<(std::ostream &o, LibLoader const &i);


#endif
