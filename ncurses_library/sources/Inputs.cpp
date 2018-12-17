
#include "../includes/Inputs.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*            Accessors            */
/* ******************************* */

int Inputs::getInput() const {
    return getch();
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
