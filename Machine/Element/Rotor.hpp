#ifndef ROTOR_HPP
#define ROTOR_HPP

#include "../../Util.h"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

class Rotor: public Element{
public:
    Rotor(shared_ptr<Instance>);

    int getInstance(int);

    void setMap(vector<int>);

    void printname();

    void setNextRotor(shared_ptr<Rotor>);
    shared_ptr<Rotor> getNextRotor();

    bool rotate();

private:
    shared_ptr<Mapper> mapForward;
    shared_ptr<Mapper> mapBackward;
    shared_ptr<Instance> instance;
    shared_ptr<Rotor> nextRotor;

    int rotation;
};

#endif
