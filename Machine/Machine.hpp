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

//Machine is usued to initialise a working copy of enigma
class Machine {
public:
    Machine(int argc, char** argv);

    //Simulate the output for a given char input into the Machine
    char simulate(char);

private:
    shared_ptr<Element> starter;
    shared_ptr<Element> current;

    shared_ptr<Instance> instance;

    shared_ptr<Rotor> rotorChain;
    shared_ptr<Rotor> lastRotor;

    std::stack<shared_ptr<Element>> stack;

    //Rotates the Machine after every input
    void rotate();

    //Adds an Element (a component) to the Machine
    void addElement(shared_ptr<Element>);
    //Link the Element as the previous's next
    void addToNext(shared_ptr<Element>);
    //Link the Element as the next's previous
    void addToPrevious(shared_ptr<Element>);

    //Add the rotor to the rotor cascade
    void addToRotors(shared_ptr<Rotor>);

    //Add a Rotor Element to the Machine
    void addRotor(vector<int>);
    //Add a Plugboard Element to the Machine
    void addPlugboard(vector<int>);
    //Package all elements together
    void assemble();
};

#endif
