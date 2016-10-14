#include "Rotor.hpp"

Rotor::Rotor(shared_ptr<Instance> instance): Element(instance) {
    this->instance = instance;
    this->mapForward = make_shared<Mapper>();
    this->mapBackward = make_shared<Mapper>();

    rotation = 0;
}

void Rotor::setMap(vector<int> vector) {
    mapForward->populateForwardRotor(vector);
    mapBackward->populateBackwardRotor(vector);
}

int Rotor::getInstance(int x) {
    //cout << "Rotation: " << rotation << endl;
    if (instance->getVerse() == Instance::Status::FORWARD) {
        return mapForward->getMappedIntRot(x, rotation);
    } else {
        return mapBackward->getMappedIntRot(x, rotation);
    }
}

void Rotor::setNextRotor(shared_ptr<Rotor> rotor) {
    this->nextRotor = rotor;
}

shared_ptr<Rotor> Rotor::getNextRotor() {
    return this->nextRotor;
}

bool Rotor::rotate() {
    rotation = mod((rotation + 1), 26);

    return rotation == 0;
}

void Rotor::printname() {
    cout << "Rotor" << endl;
}
