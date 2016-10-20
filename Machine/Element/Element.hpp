#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "../../Util.hpp"
#include "../Instance.hpp"

//Elements are the components inside the Machine
class Element {
public:
    Element(shared_ptr<Instance>);
    //Returns the Element subsequent to the current one.
    //It is affected by the BACKWARDS/FORWARDS Status described by Instance
    shared_ptr<Element> forward();

    //Encripts a given int, calling upon getInstance().
    virtual int pass(int);
    //Maps the given int to its encription.
    virtual int getInstance(int) = 0;

    //Set the Element following the current one.
    void setNext(shared_ptr<Element>);
    //Set the Element preceeding the current one.
    void setPrevious(shared_ptr<Element>);

    virtual void printname() = 0;

private:
    shared_ptr<Element> next;
    shared_ptr<Element> previous;

protected:
    shared_ptr<Instance> instance;
};

#endif
