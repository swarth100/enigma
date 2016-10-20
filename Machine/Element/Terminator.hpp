#ifndef TERMINATOR_HPP
#define TERMINATOR_HPP

#include "../../Util.hpp"
#include "../Instance.hpp"
#include "Element.hpp"

//Final Element in the Machine.
class Terminator: public Element{
public:
    Terminator(shared_ptr<Instance>);

    //Overrides the pass method to actually return the encripted char
    int pass(int);

    int getInstance(int);

    void printname();
};

#endif
