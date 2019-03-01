
#ifndef MLXDATA_HPP
# define MLXDATA_HPP

# include <iostream>

struct MlxData {
public:
    void *getMlx() const;

    void setMlx(void *mlx);

    void *getWindow() const;

    void setWindow(void *window);

    void *getImg_addr() const;

    void setImg_addr(void *img_addr);

    char *getImg_content() const;

    void setImg_content(char *img_content);

    int *getSize_line() const;

    void setSize_line(int *size_line);

    int *getBits_per_pixel() const;

    void setBits_per_pixel(int *bits_per_pixel);

    int *getEndian() const;

    void setEndian(int *endian);

    int getXSize() const;

    void setXSize(int xSize);

    int getYSize() const;

    void setYSize(int ySize);

    int     *size_line;
    int     *bits_per_pixel;
    int     *endian;

private:
    void    *mlx;
    void    *window;
    void    *img_addr;
    char    *img_content;

    int     xSize;
    int     ySize;
};


#endif