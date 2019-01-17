
#include "../includes/Inputs.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*            Accessors            */
/* ******************************* */

eInputs Inputs::getInput() const {
    switch(getch()) {
        case KEY_EXIT:
            return eInputs::quit;
        case '1':
            return eInputs::lib1;
        case '2':
            return eInputs::lib2;
        case '3':
            return eInputs::lib3;
        case ' ':
            return eInputs::pause;
        case KEY_LEFT:
            return eInputs::left;
        case KEY_RIGHT:
            return eInputs::right;
        case KEY_UP:
            return eInputs::up;
        case KEY_DOWN:
            return eInputs::down;
        default:
            return eInputs::noInput;
    }
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
