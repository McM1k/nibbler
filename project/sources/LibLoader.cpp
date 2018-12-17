#include "../includes/LibLoader.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

LibLoader::LibLoader(eLibs _libName) : libName(_libName), LIBSNUMBER(4) {
    char *libs[LIBSNUMBER];

    libs[eLibs::ncursesLib] = const_cast<char *>("libs/libncurses.so");

    dl_handle = dlopen(libs[libName], RTLD_NOW | RTLD_LOCAL);

    if (!dl_handle) {
        throw DLExceptions();
    }
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

LibLoader::eLibs LibLoader::getLibName() const {
    return libName;
}

char *const *LibLoader::getLibs() const {
    return libs;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

const char *LibLoader::DLExceptions::what() const noexcept {
    return dlerror();
}