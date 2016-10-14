#ifndef STARTER_HPP
#define STARTER_HPP

#include "../../Util.h"
#include "../Instance.hpp"
#include "Element.hpp"

class Starter: public Element{
public:
    Starter(shared_ptr<Instance>);

    int getInstance(int);

    void printname();
};

#endif
