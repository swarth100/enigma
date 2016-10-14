#include "Reflector.hpp"

Reflector::Reflector(shared_ptr<Instance> instance): Element(instance) {
    this->instance = instance;
    this->map = make_shared<Mapper>();
    map->populateReflector();
}

int Reflector::getInstance(int x) {
    this->changeVerse();
    return map->getMappedInt(x);
}

void Reflector::changeVerse() {
    this->instance->changeVerse();
}

void Reflector::printname() {
    cout << "Reflector" << endl;
}
