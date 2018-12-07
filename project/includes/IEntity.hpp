
#ifndef IENTITY_HPP
# define IENTITY_HPP

# include <iostream>

class IEntity {
public:
    virtual void display_board() = 0;
    virtual void display_score(int score) = 0;
    virtual void display_snake(std::list<Bloc> snake) = 0;
    virtual void display_text(std::string str) = 0;
};


#endif