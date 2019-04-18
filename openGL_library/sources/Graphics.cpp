
#include "../includes/Graphics.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Graphics::Graphics(int x, int y) : xSize((x + 5) * 20), ySize(y * 20){
    int ac = 1;
    char *av[1] = {(char*)"Nibbler"};
    glutInit(&ac,av);
    glutInitWindowPosition(-1, -1);
    glutInitWindowSize(this->xSize, this->ySize);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    this->windowIdentifier = glutCreateWindow(" Nibbler - OpenGLUT ");

    this->displayer = Displayer(this->xSize, this->ySize);
    this->inputs = Inputs();

    glutDisplayFunc(&renderScene);
    glutIdleFunc(&renderScene);
    glutKeyboardFunc(&processNormalKeys);
    glutSpecialFunc(&processSpecialKeys);
    glutMainLoop();
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
void Graphics::display(Map const &, UI const &) {

}

eInputs Graphics::getInput() const {
    return Inputs::lastInput;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

Graphics *newGraphics(int x, int y){
    return new Graphics(x ,y);
}

void deleteGraphics(Graphics *graphics){
    delete graphics;
}

