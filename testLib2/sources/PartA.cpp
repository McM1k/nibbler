
#include "../includes/PartA.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

PartA::PartA() {

}

PartA::PartA(int) {

}

PartA::PartA(PartA const &src) {
    *this = src;
}

PartA::~PartA() {

}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

PartA &PartA::operator=(PartA const &rhs) {
    if (this != &rhs) {

    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, PartA const &instance) {
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

