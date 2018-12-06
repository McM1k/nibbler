#include <dlfcn.h>
#include <iostream>

void dlerror_wrapper() {
    std::cerr << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}

int main() {
    void    *dl_handle;

    std::string    (*partAFunct)(void);
    std::string    (*partBFunct)(void);

    dl_handle = dlopen("libs/lib1.so", RTLD_LAZY | RTLD_LOCAL);

    if(!dl_handle)
        dlerror_wrapper();

    partAFunct = (std::string (*)(void))dlsym(dl_handle, "saySomethingA");

    if(!partAFunct)
        dlerror_wrapper();

    partBFunct = (std::string (*)(void))dlsym(dl_handle, "saySomethingB");

    if(!partBFunct)
        dlerror_wrapper();

    std::cout << partAFunct() << std::endl;
    std::cout << partBFunct() << std::endl;

    dlclose(dl_handle);
    return 1;
}