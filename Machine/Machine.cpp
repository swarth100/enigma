#include "Machine.hpp"

Machine::Machine(int argc, char** argv) {
    this->instance = make_shared<Instance>();
    this->starter = make_shared<Starter>(instance);
    this->current = starter;

    this->rotorChain = make_shared<Rotor>(instance);
    this->lastRotor = rotorChain;

    int argInt = 1;
    int maxArgc = argc-1;

    if (maxArgc <= 0) {
        cout << "ERROR: No Input Files" << endl;
        exit (1);
    }

    addPlugboard(parse(argv[maxArgc]));

    while (argInt < maxArgc) {
        addRotor(parse(argv[argInt]));
        argInt ++;
    }

    assemble();
}

char Machine::simulate(char c) {
    int result;
    int valueC = c - BASE_CHAR;

    //If the Input is INVALID, exit
    if (valueC < 0 || valueC > MAX_ALPHABET) {
        cout << endl;
        cout << "ERROR: Invalid Input Character: " << c << endl;
        exit (1);
    }

    result = starter->pass(valueC);
    rotate();
    return (result + BASE_CHAR);
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
    lastRotor = rotor;
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
