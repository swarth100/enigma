#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include "../../Util.hpp"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

//Reflector Element
class Reflector: public Element{
public:
    Reflector(shared_ptr<Instance>);

    //Applies a 13 offset to the given int.
    int getInstance(int);

    //Changes the verse of encription for the Instance.
    void changeVerse();

    void printname();

private:
    shared_ptr<Mapper> map;
};

#endif
