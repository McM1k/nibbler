/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:09:06 by gboudrie          #+#    #+#             */
/*   Updated: 2019/01/29 19:09:06 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

# include <iostream>
# include <ncurses.h>
# include "../../project/includes/IGraphics.hpp"
#include "Display.hpp"
#include "Inputs.hpp"

class Graphics : public IGraphics {
public:
    Graphics(void) = default;
    Graphics(int x, int y);
    Graphics(Graphics const &src) = default;
    virtual ~Graphics(void);
    Graphics &operator=(Graphics const &rhs) = default;

    void display(Map const &map, UI const &gameInfo);
    eInputs getInput() const;

private:
    WINDOW *window;
    Display display1;
    Inputs inputs;

};

extern "C" {
Graphics *newGraphics(int x, int y);
void deleteGraphics(Graphics *graphics);
}

#endif