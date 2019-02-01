
#include "../includes/Display.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Display::Display(MlxData _mlxData) : mlxData(_mlxData) {}
/* ******************************* */
/*            Accessors            */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */
void    Display::put_pixel(int x, int y, char transparency, char red, char green, char blue) {
    auto lineSize = *this->mlxData.getSize_line();
    auto pixelSize = *this->mlxData.getBits_per_pixel();
    auto imageContent = this->mlxData.getImg_content();
    auto xMax = this->mlxData.getXSize();
    auto yMax = this->mlxData.getYSize();
    auto pixelAddr = x * pixelSize + y * lineSize;


    if (!(x >= lineSize || x < 0 || y < 0 || x >= xMax || y >= yMax)) {
        imageContent[pixelAddr] = transparency;
        imageContent[pixelAddr + 1] = red;
        imageContent[pixelAddr + 2] = green;
        imageContent[pixelAddr + 3] = blue;
    }
}

void    Display::clean_image() {
    auto imageContent = this->mlxData.getImg_content();
    auto imageByteSize = this->mlxData.getXSize() * this->mlxData.getYSize() * *this->mlxData.getBits_per_pixel();

    for (auto i = 0; i < imageByteSize; i++)
        imageContent[i] = 0;
}

void Display::display(Map &map, UI &ui) {
    clean_image();

    print_background(map);
    print_borders(map);
    print_obstacles(map);
    print_fruit(map);
    print_snake(map);

    mlx_put_image_to_window(this->mlxData.getMlx(), this->mlxData.getWindow(), this->mlxData.getImg_addr(), 0, 0);
}


void Display::print_background(Map &map) {
    for ()
}

void Display::print_borders(Map &map) {

}

void Display::print_obstacles(Map &map) {

}

void Display::print_fruit(Map &map) {

}

void Display::print_snake(Map &map) {

}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

