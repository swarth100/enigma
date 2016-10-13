#ifndef PLUGBOARD_HPP
#define PLUGBOOARD_HPP

#include "../../Util.h"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

class Plugboard: public Element{
public:
    Plugboard(Instance);

    int getInstance();

private:
    Mapper map;
    Instance instance;
};

#endif
