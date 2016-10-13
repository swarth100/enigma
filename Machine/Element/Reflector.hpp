#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include "../../Util.h"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

class Reflector: public Element{
public:
    Reflector(Instance);

    int getInstance();

    void changeVerse();

private:
    Mapper map;
    Instance instance;
};

#endif
