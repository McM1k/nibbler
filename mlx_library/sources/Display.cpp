
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

void Display::select_color(int x, int y, char color) {
    switch (color) {
        case FRUIT_COLOR_1:
            put_pixel(x, y, 0, 0xEE, 0x33, 0x33);
        case FRUIT_COLOR_2:
            put_pixel(x, y, 0, 0xFF, 0xFF, 0xFF);
        case SNAKE_COLOR_1:
            put_pixel(x, y, 0, 0x44, 0xDD, 0x33);
        case SNAKE_COLOR_2:
            put_pixel(x, y, 0, 0xFF, 0xFF, 0xCC);
        case ROCK_COLOR_1:
            put_pixel(x, y, 0, 0x99, 0x99, 0x99);
        case ROCK_COLOR_2:
            put_pixel(x, y, 0, 0xBB, 0x33, 0x66);
    }
}

void Display::put_square(int xSquare, int ySquare, char img[10][10], Map::eDirection direction){
    int x,y;

    if (direction == Map::eDirection::right) {
        for (x = 0; x < 10; x++){
            for (y = 0; y < 10; y++){
                select_color(xSquare + x, ySquare + y, img[x][y]);
            }
        }
    }
    else if (direction == Map::eDirection::left) {
        for (x = 9; x >= 0; x--){
            for (y = 9; y >= 0; y--){
                select_color(xSquare + x, ySquare + y, img[x][y]);
            }
        }
    }
    else if (direction == Map::eDirection::down) {
        for (x = 0; x < 10; x++){
            for (y = 9; y >= 0; y--){
                select_color(xSquare + x, ySquare + y, img[x][y]);
            }
        }
    }
    else if (direction == Map::eDirection::up) {
        for (x = 9; x >= 0; x--){
            for (y = 0; y < 10; y++){
                select_color(xSquare + x, ySquare + y, img[x][y]);
            }
        }
    }
}

Map::eDirection Display::select_direction(std::list<Bloc>::const_iterator primary_bloc_it,
                                          std::list<Bloc>::const_iterator linked_bloc_it) {

    if (linked_bloc_it->getX() != primary_bloc_it->getX()) {//right or left
        if (linked_bloc_it->getX() == primary_bloc_it->getX() + 1) {//right
            return Map::eDirection::right;
        } else {//left
            return Map::eDirection::left;
        }
    }
    else {//up or down
        if (linked_bloc_it->getY() == primary_bloc_it->getY() + 1) {//down
            return Map::eDirection::down;
        } else {//up
            return Map::eDirection::up;
        }
    }
}

void    Display::clean_image() {
    auto imageContent = this->mlxData.getImg_content();
    auto imageByteSize = this->mlxData.getXSize() * this->mlxData.getYSize() * *this->mlxData.getBits_per_pixel();

    for (auto i = 0; i < imageByteSize; i++)
        imageContent[i] = 0;
}

void Display::display(Map const &map, UI const &ui) {
    (void)ui;
    clean_image();

    print_background(map);
    print_obstacles(map.getObstacles());
    print_fruit(map.getFruit());
    print_snake(map.getSnake());

    mlx_put_image_to_window(this->mlxData.getMlx(), this->mlxData.getWindow(), this->mlxData.getImg_addr(), 0, 0);
}


void Display::print_background(Map const &map) {
    for (int x = 0; x < map.getXSize() * 10; x++){
        for (int y = 0; y < map.getYSize() * 10; y++){
            put_pixel(x, y, 0, 0xDD, 0xDD, 0x55);
        }
    }
}

void Display::print_obstacles(std::list<Bloc> obstacles) {
    for (auto current_obstacle : obstacles) {
        auto xSquare = current_obstacle.getX() * 10;
        auto ySquare = current_obstacle.getY() * 10;

        put_square(xSquare, ySquare, rock_img, Map::eDirection::right);
    }
}

void Display::print_fruit(Bloc fruit) {
    auto xSquare = fruit.getX() * 10;
    auto ySquare = fruit.getY() * 10;

    put_square(xSquare, ySquare, fruit_img, Map::eDirection::right);
}

void Display::print_snake(std::list<Bloc> snake) {
    std::list<Bloc>::const_iterator prev = snake.begin();
    std::list<Bloc>::const_iterator next = snake.begin();
    next++;
    Map::eDirection dir;

    for (std::list<Bloc>::const_iterator it = snake.begin(); it != snake.end(); it++){
        auto xSquare = it->getX() * 10;
        auto ySquare = it->getY() * 10;

        dir = select_direction(it, next);
        if (it == snake.begin()) //TAIL
            put_square(xSquare, ySquare, tail_img, dir);
        else{ //BODY
            put_square(xSquare, ySquare, body_junction_img, dir);
            put_square(xSquare, ySquare, body_center_img, Map::eDirection::right);
            dir = select_direction(it, prev);
            put_square(xSquare, ySquare, body_junction_img, dir);

            prev++;
        }
        if (next != snake.end())
            next++;
    }
    //HEAD
    dir = select_direction(snake.end(), prev);
    put_square(snake.end()->getX() * 10, snake.end()->getY() * 10, head_img, dir);
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

const char* Display::BrokenSnakeException::what() const throw(){
    return "Snake is broken";
}