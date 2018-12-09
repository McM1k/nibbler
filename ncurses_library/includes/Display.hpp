
#ifndef DISPLAY_HPP
# define DISPLAY_HPP
# include "../../project/includes/IEntity.hpp"
# include "../../project/includes/Map.hpp"
# include "../../project/includes/UI.hpp"
# include <iostream>

class Display : public IEntity{
public:
    Display(void) = default;
    Display(Display const &src) = default;
    virtual ~Display(void) = default;
    Display &operator=(Display const &rhs) = default;

    void display(Map const &map, UI const &gameInfo) const;
private:

};


#endif