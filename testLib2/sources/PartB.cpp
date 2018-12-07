
#include "PartB.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

PartB::PartB() {

}

PartB::PartB(int) {

}

PartB::PartB(PartB const &src) {
    *this = src;
}

PartB::~PartB() {

}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

PartB &PartB::operator=(PartB const &rhs) {
    if (this != &rhs) {

    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, PartB const &instance) {
    o << "The value of  is : ";

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */



/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

