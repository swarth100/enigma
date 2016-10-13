#include "Machine.hpp"

Machine::Machine() {
    this->instance = make_shared<Instance>();
    this->starter = make_shared<Starter>(instance);
    this->current = starter;
}

int Machine::simulate(int x) {
    return starter->pass(x);
}

void Machine::addRotor(vector<int> vector) {
    shared_ptr<Rotor> rotor = make_shared<Rotor>(instance);

    rotor->setMap(vector);

    shared_ptr<Element> element = rotor;

    addElement(element);
}

void Machine::addPlugboard(vector<int> vector) {
    shared_ptr<Plugboard> plugboard = make_shared<Plugboard>(instance);

    plugboard->setMap(vector);

    shared_ptr<Element> element = plugboard;

    addElement(element);
}

void Machine::addElement(shared_ptr<Element> element) {
    stack.push(element);
    addToCurrent(element);
}

void Machine::addToCurrent(shared_ptr<Element> element) {
    current->setNext(element);
    current = element;
}

void Machine::assemble() {
    shared_ptr<Element> reflector = make_shared<Reflector>(instance);
    addToCurrent(reflector);

    //Possible cause of Rotor Chain errors:
    rotorChain = make_shared<Rotor>(instance);

    while (!stack.empty()) {
        shared_ptr<Element> top = stack.top();
        addToCurrent(top);
        stack.pop();

        //Add enum to all classes
        //Return that enum and check
    }
}
