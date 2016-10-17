#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include "../../Util.hpp"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

class Reflector: public Element{
public:
    Reflector(shared_ptr<Instance>);

    int getInstance(int);

    void changeVerse();

    void printname();

private:
    shared_ptr<Mapper> map;
};

#endif
