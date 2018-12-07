#include <dlfcn.h>
#include <iostream>
#include "../includes/IPartA.hpp"

typedef std::string (*functString)(void);
typedef IPartA *(*functNewPartA)(void);
typedef void (*functDeletePartA)(IPartA*);

typedef void *handle;

void dlerror_wrapper() {
    std::cerr << "Error: " << dlerror() << std::endl;
    exit(EXIT_FAILURE);
}

void loadLib(char const *libName,
        handle &dl_handle,
        functNewPartA &newPartAFunct,
        functDeletePartA &deletePartAFunct,
        functString &partBFunct) {

    dl_handle = dlopen(libName, RTLD_LAZY | RTLD_LOCAL);

    if(!dl_handle)
        dlerror_wrapper();

    newPartAFunct = (IPartA *(*)(void))dlsym(dl_handle, "newPartA");

    if(!newPartAFunct)
        dlerror_wrapper();

    deletePartAFunct = (void (*)(IPartA*))dlsym(dl_handle, "destroyPartA");

    if(!deletePartAFunct)
        dlerror_wrapper();

    partBFunct = (std::string (*)(void))dlsym(dl_handle, "saySomethingB");

    if(!partBFunct)
        dlerror_wrapper();

    dlclose(dl_handle);
}

int main() {
    handle dl_handle;

    functNewPartA       newPartAFunct;
    functDeletePartA    deletePartAFunct;
    functString         partBFunct;

    auto lib1Name = "./libs/lib1.so";
    auto lib2Name = "./libs/lib2.so";

    loadLib(lib1Name, dl_handle, newPartAFunct, deletePartAFunct, partBFunct);

    IPartA *partA = newPartAFunct();

    std::cout << partA->saySomething() << std::endl;
    std::cout << partBFunct() << std::endl;

    deletePartAFunct(partA);

    loadLib(lib2Name, dl_handle, newPartAFunct, deletePartAFunct, partBFunct);

    partA = newPartAFunct();

    std::cout << partA->saySomething() << std::endl;
    std::cout << partBFunct() << std::endl;

    deletePartAFunct(partA);

    return 1;
}