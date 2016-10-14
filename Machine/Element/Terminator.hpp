#ifndef TERMINATOR_HPP
#define TERMINATOR_HPP

#include "../../Util.h"
#include "../Instance.hpp"
#include "Element.hpp"

class Terminator: public Element{
public:
    Terminator(shared_ptr<Instance>);

    int pass(int);

    int getInstance(int);

    void printname();
};

#endif
