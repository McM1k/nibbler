
#include "../includes/MlxData.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*            Accessors            */
/* ******************************* */
void *MlxData::getMlx() const {
    return mlx;
}

void MlxData::setMlx(void *mlx) {
    MlxData::mlx = mlx;
}

void *MlxData::getWindow() const {
    return window;
}

void MlxData::setWindow(void *window) {
    MlxData::window = window;
}

void *MlxData::getImg_addr() const {
    return img_addr;
}

void MlxData::setImg_addr(void *img_addr) {
    MlxData::img_addr = img_addr;
}

char *MlxData::getImg_content() const {
    return img_content;
}

void MlxData::setImg_content(char *img_content) {
    MlxData::img_content = img_content;
}

int *MlxData::getSize_line() {
    return &size_line;
}

void MlxData::setSize_line(int size_line) {
    MlxData::size_line = size_line;
}

int *MlxData::getBits_per_pixel() {
    return &bits_per_pixel;
}

void MlxData::setBits_per_pixel(int bits_per_pixel) {
    MlxData::bits_per_pixel = bits_per_pixel;
}

int *MlxData::getEndian() {
    return &endian;
}

void MlxData::setEndian(int endian) {
    MlxData::endian = endian;
}

int MlxData::getXSize() const {
    return xSize;
}

void MlxData::setXSize(int xSize) {
    MlxData::xSize = xSize;
}

int MlxData::getYSize() const {
    return ySize;
}

void MlxData::setYSize(int ySize) {
    MlxData::ySize = ySize;
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

