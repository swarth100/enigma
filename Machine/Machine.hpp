#ifndef MACHINE_HPP
#define MACHINE_HPP

#include "../Util.h"
#include "Element/Element.hpp"
#include "Element/Rotor.hpp"
#include "Element/Plugboard.hpp"
#include "Element/Reflector.hpp"
#include "Element/Starter.hpp"
#include "Element/Terminator.hpp"

class Machine {
public:
    Machine();
    int simulate(int);

private:
    shared_ptr<Element> enigma;
    shared_ptr<Rotor> rotorChain;
};

#endif
