#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "../../Util.h"
#include "../Instance.hpp"

class Element {
public:
    Element(shared_ptr<Instance>);
    shared_ptr<Element> forward();

    int pass(int);
    virtual int getInstance(int)=0;

    void setNext(shared_ptr<Element>);

private:
    shared_ptr<Element> next;
    shared_ptr<Instance> instance;
};

#endif
