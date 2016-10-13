#ifndef MACHINE_HPP
#define MACHINE_HPP

#include "../Util.h"
#include "Instance.hpp"
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

    void addRotor(vector<int>);
    void addPlugboard(vector<int>);

    void assemble();

private:
    shared_ptr<Element> starter;
    shared_ptr<Element> current;
    shared_ptr<Instance> instance;
    shared_ptr<Rotor> rotorChain;

    std::stack<shared_ptr<Element>> stack;

    void rotate();

    void addElement(shared_ptr<Element>);
    void addToCurrent(shared_ptr<Element>);
};

#endif
