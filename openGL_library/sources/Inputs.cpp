
#include "../includes/Inputs.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Inputs::Inputs() { lastInput = eInputs::noInput; }

/* ******************************* */
/*            Accessors            */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

/* ******************************* */
void processNormalKeys(unsigned char key, int x, int y) {
    (void)x;
    (void)y;

    switch(key) {
        case ' ' :
            Inputs::lastInput = eInputs::pause;
            break;

        case 27 :
            Inputs::lastInput = eInputs::quit;
            break;
        default:
            Inputs::lastInput = eInputs::noInput;
            break;
    }
}

void processSpecialKeys(int key, int x, int y) {
    (void)x;
    (void)y;

    switch(key) {
        case GLUT_KEY_UP :
            Inputs::lastInput = eInputs::up;
            break;
        case GLUT_KEY_DOWN :
            Inputs::lastInput = eInputs::down;
            break;
        case GLUT_KEY_LEFT :
            Inputs::lastInput = eInputs::left;
            break;
        case GLUT_KEY_RIGHT :
            Inputs::lastInput = eInputs::right;
            break;
        case GLUT_KEY_F1 :
            Inputs::lastInput = eInputs::lib1;
            break;
        case GLUT_KEY_F2 :
            Inputs::lastInput = eInputs::lib2;
            break;
        case GLUT_KEY_F3 :
            Inputs::lastInput = eInputs::lib3;
            break;
        default:
            Inputs::lastInput = eInputs::noInput;
    }
}