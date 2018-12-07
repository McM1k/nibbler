
#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <iostream>

class Display {
public:
    Display(void) = default;

    Display(Display const &src) = default;

    virtual ~Display(void) = default;

    Display &operator=(Display const &rhs) = default;

    std::ostream &operator<<(std::ostream &o);

private:

};


#endif