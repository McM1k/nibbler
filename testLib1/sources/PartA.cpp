
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

std::string PartA::returnString() {
    return "PartA";
}

extern "C" std::string saySomethingA() {
    PartA partA;

    return partA.returnString();
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

