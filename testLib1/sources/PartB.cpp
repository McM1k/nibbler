
#include "../includes/PartB.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

std::ostream &operator<<(std::ostream &o, PartB const &instance) {
    o << "partB";

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

std::string PartB::returnString() {
    return "PartB";
}

extern "C" std::string saySomethingB() {
    PartB partB;

    return partB.returnString();
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

