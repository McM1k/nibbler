
#include "../includes/Inputs.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*            Accessors            */
/* ******************************* */

eInputs Inputs::getInput() const {
    return static_cast<eInputs>(getch());
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */

Inputs *newInputs() {
    return new Inputs();
}


void deleteInputs(Inputs *inputs) {
    delete inputs;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */
