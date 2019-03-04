
#include <thread>
#include "../includes/Graphics.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Graphics::Graphics(int x, int y) : xSize(x * 10), ySize((y + 5) * 10) {
    this->mlxData.setMlx(mlx_init());
    if (!this->mlxData.getMlx()) {throw UnableToInitMlx();}

    this->mlxData.setWindow(mlx_new_window(this->mlxData.getMlx(), this->xSize, this->ySize, (char *)"Nibbler - MLX"));
    if (!this->mlxData.getWindow()) {throw UnableToInitWindow();}

    this->mlxData.setImg_addr(mlx_new_image(this->mlxData.getMlx(), this->xSize, this->ySize));
    if (!this->mlxData.getImg_addr()) {throw UnableToInitImageAddress();}

    this->mlxData.setImg_content(mlx_get_data_addr(this->mlxData.getImg_addr(), this->mlxData.getBits_per_pixel(),
                                                   this->mlxData.getSize_line(), this->mlxData.getEndian()));

    if (!this->mlxData.getImg_content()) {throw UnableToInitImageContent();}

    mlx_put_image_to_window(mlxData.getMlx(), mlxData.getWindow(), mlxData.getImg_addr(), 0, 0);

    this->mlxData.setXSize(this->xSize);
    this->mlxData.setYSize(this->ySize);

    this->display1 = Display(this->mlxData);
    this->inputs = Inputs(this->mlxData);
}
/* ******************************* */
/*            Accessors            */
/* ******************************* */
eInputs Graphics::getInput() const {
    return this->inputs.getCurrent_input();
}

void Graphics::display(Map const &map, UI const &gameInfo) {
    this->display1.display(map, gameInfo);
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */

/* ******************************* */
/*            Exceptions           */
/* ******************************* */
const char* Graphics::UnableToInitMlx::what() const noexcept{
    return "Unable to initialize mlx";
}

const char* Graphics::UnableToInitWindow::what() const noexcept{
    return "Unable to initialize window";
}

const char* Graphics::UnableToInitImageAddress::what() const noexcept{
    return "Unable to initialize image address";
}

const char* Graphics::UnableToInitImageContent::what() const noexcept{
    return "Unable to initialize image content";
}



Graphics *newGraphics(int x, int y) {
    return new Graphics(x, y);
}

void deleteGraphics(Graphics *graphics) {
    delete graphics;
}