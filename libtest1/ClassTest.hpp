
#ifndef CLASSTEST_HPP
# define CLASSTEST_HPP

# include <iostream>

class ClassTest {
public:
    ClassTest(void) = default;

    ClassTest(ClassTest const &src) = default;

    virtual ~ClassTest(void) = default;

    ClassTest &operator=(ClassTest const &rhs) = default; //equals

private:

};

std::ostream &operator<<(std::ostream &o, ClassTest const &i);

#endif