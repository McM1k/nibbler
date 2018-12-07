
#include "../includes/PartA.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

std::ostream &operator<<(std::ostream &o, PartA const &instance) {
    o << "partA";

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

std::string PartA::saySomething() const {
    return "Something";
}

PartA   *newPartA() {
    return new PartA();
}

void    destroyPartA(PartA *partA) {
    delete partA;
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */
