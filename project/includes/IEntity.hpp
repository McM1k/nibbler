
#ifndef IENTITY_HPP
# define IENTITY_HPP

# include <iostream>

class IEntity {
public:
    virtual void display(Map const &map, UI const &gameInfo) const = 0;
};


#endif