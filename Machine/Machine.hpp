#ifndef MACHINE_HPP
#define MACHINE_HPP

#include "../Util.hpp"
#include "Instance.hpp"
#include "Element/Element.hpp"
#include "Element/Rotor.hpp"
#include "Element/Plugboard.hpp"
#include "Element/Reflector.hpp"
#include "Element/Starter.hpp"
#include "Element/Terminator.hpp"

class Machine {
public:
    Machine(int, char**);

    char simulate(char);

private:
    shared_ptr<Element> starter;
    shared_ptr<Element> current;

    shared_ptr<Instance> instance;

    shared_ptr<Rotor> rotorChain;
    shared_ptr<Rotor> lastRotor;

    std::stack<shared_ptr<Element>> stack;

    void rotate();

    void addElement(shared_ptr<Element>);
    void addToNext(shared_ptr<Element>);
    void addToPrevious(shared_ptr<Element>);

    void addToRotors(shared_ptr<Rotor>);

    void addRotor(vector<int>);
    void addPlugboard(vector<int>);
    void assemble();
};

#endif
