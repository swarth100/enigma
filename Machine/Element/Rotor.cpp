#include "Rotor.hpp"

Rotor::Rotor(shared_ptr<Instance> instance): Element(instance) {
    this->instance = instance;
    this->mapForward = make_shared<Mapper>();
    this->mapBackward = make_shared<Mapper>();
}

void Rotor::setMap(vector<int> vector) {
    mapForward->populateForwardRotor(vector);
    mapBackward->populateBackwardRotor(vector);
}

int Rotor::getInstance(int x) {
    if (instance->getVerse() == Instance::Status::FORWARD) {
        return mapForward->getMappedInt(x);
    } else {
        return mapBackward->getMappedInt(x);
    }
}

void Rotor::setNextRotor(shared_ptr<Rotor> rotor) {
    this->nextRotor = rotor;
}

shared_ptr<Rotor> Rotor::getNextRotor() {
    return this->nextRotor;
}
