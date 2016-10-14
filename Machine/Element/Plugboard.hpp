#ifndef PLUGBOARD_HPP
#define PLUGBOOARD_HPP

#include "../../Util.h"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

class Plugboard: public Element{
public:
    Plugboard(shared_ptr<Instance>);

    int getInstance(int);

    void setMap(vector<int>);

    void printname();

private:
    shared_ptr<Mapper> map;
    shared_ptr<Instance> instance;
};

#endif
