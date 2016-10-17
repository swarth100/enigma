#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "../../Util.hpp"
#include "../Instance.hpp"

class Element {
public:
    Element(shared_ptr<Instance>);
    shared_ptr<Element> forward();

    virtual int pass(int);
    virtual int getInstance(int) = 0;

    void setNext(shared_ptr<Element>);
    void setPrevious(shared_ptr<Element>);

    virtual void printname() = 0;

private:
    shared_ptr<Element> next;
    shared_ptr<Element> previous;

protected:
    shared_ptr<Instance> instance;
};

#endif
