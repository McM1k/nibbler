
#ifndef IENTITY_HPP
# define IENTITY_HPP

# include <iostream>
# include "Map.hpp"
# include "UI.hpp"

class IEntity {
public:
    virtual void display(Map const &map, UI const &gameInfo) const = 0;
};


#endif