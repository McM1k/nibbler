
#ifndef IENTITY_HPP
# define IENTITY_HPP

# include <iostream>

class IEntity {
public:
    virtual void display_map(Map &map) const = 0;
    virtual void display_text(std::string &str) const = 0;
};


#endif