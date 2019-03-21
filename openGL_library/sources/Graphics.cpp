
#include "../includes/Graphics.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Graphics::Graphics(int x, int y) : xSize(x), ySize(y){

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
void Graphics::display(Map const &map, UI const &gameInfo) {

}

eInputs Graphics::getInput() const {

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