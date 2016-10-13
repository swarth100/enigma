#ifndef ROTOR_HPP
#define ROTOR_HPP

#include "../../Util.h"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

class Rotor: public Element{
public:
    Rotor(Instance);

    int getInstance();

private:
    Mapper map;
    Instance instance;
};

#endif
