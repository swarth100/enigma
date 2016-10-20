#ifndef STARTER_HPP
#define STARTER_HPP

#include "../../Util.hpp"
#include "../Instance.hpp"
#include "Element.hpp"

//First Element in the Machine
//A placeholder Element upoon which to call the recursive encription
class Starter: public Element{
public:
    Starter(shared_ptr<Instance>);

    int getInstance(int);

    void printname();
};

#endif
