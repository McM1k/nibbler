/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:42:56 by gboudrie          #+#    #+#             */
/*   Updated: 2019/01/29 19:42:56 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Graphics.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */
Graphics::Graphics(int x, int y) {
//    setlocale(LC_ALL, "");
    initscr();
    this->window = newwin(y + 7, x + 2, 0, 0);
    start_color();
    cbreak();
    noecho();

    this->display1 = Display(x, y, this->window);
    this->inputs = Inputs(this->window);
}

Graphics::~Graphics() {
    delwin(this->window);
    endwin();
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
    this->display1.display(map, gameInfo);
}

eInputs Graphics::getInput() const {
    return this->inputs.getInput();
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