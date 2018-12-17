
#ifndef NIBBLER_LIBLOADER_HPP
#define NIBBLER_LIBLOADER_HPP

#include <dlfcn.h>
#include <iostream>

class LibLoader {
public:
    typedef enum {
        ncursesLib
    } eLibs;

    LibLoader() = delete;

    explicit LibLoader(eLibs _libName);

    LibLoader(LibLoader const &src) = delete;

    virtual ~LibLoader();

    LibLoader &operator=(LibLoader const &) = delete;

    eLibs getLibName() const;

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
    const int LIBSNUMBER;
    void *dl_handle;
    char *libs[3];
    const eLibs libName;

};

std::ostream &operator<<(std::ostream &o, LibLoader const &i);


#endif
