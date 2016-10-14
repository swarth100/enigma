#include "Machine.hpp"

Machine::Machine() {
    this->instance = make_shared<Instance>();
    this->starter = make_shared<Starter>(instance);
    this->current = starter;

    this->rotorChain = make_shared<Rotor>(instance);
    this->lastRotor = rotorChain;
}

int Machine::simulate(int x) {
    int result = starter->pass(x);
    rotate();
    return result;
}

void Machine::addRotor(vector<int> vector) {
    shared_ptr<Rotor> rotor = make_shared<Rotor>(instance);

    rotor->setMap(vector);

    shared_ptr<Element> element = rotor;

    addElement(element);

    addToRotors(rotor);
}

void Machine::addPlugboard(vector<int> vector) {
    shared_ptr<Plugboard> plugboard = make_shared<Plugboard>(instance);

    plugboard->setMap(vector);

    shared_ptr<Element> element = plugboard;

    addElement(element);
}

void Machine::addElement(shared_ptr<Element> element) {
    stack.push(element);
    addToNext(element);
}

void Machine::addToNext(shared_ptr<Element> element) {
    current->setNext(element);
    current = element;
}

void Machine::addToPrevious(shared_ptr<Element> element) {
    current->setPrevious(element);
    current = element;
}

void Machine::addToRotors(shared_ptr<Rotor> rotor) {
    lastRotor->setNextRotor(rotor);
    current = rotor;
}

void Machine::assemble() {
    shared_ptr<Element> reflector = make_shared<Reflector>(instance);

    shared_ptr<Element> tmp = current;
    addToNext(reflector);
    addToNext(tmp);

    while (!stack.empty()) {
        shared_ptr<Element> top = stack.top();
        addToPrevious(top);
        stack.pop();
    }

    shared_ptr<Element> terminator = make_shared<Terminator>(instance);
    addToPrevious(terminator);
}

void Machine::rotate() {
    shared_ptr<Rotor> tmp = rotorChain->getNextRotor();

    while (tmp != NULL && tmp->rotate()) {
        tmp = tmp->getNextRotor();
    }
}
