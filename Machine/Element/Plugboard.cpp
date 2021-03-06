#include "Plugboard.hpp"

Plugboard::Plugboard(shared_ptr<Instance> instance): Element(instance) {
    this->map = make_shared<Mapper>();
}

int Plugboard::getInstance(int x) {
    return map->getMappedInt(x);
}

void Plugboard::setMap(vector<int> vector) {
    map->populatePlugboard(vector);
}

void Plugboard::printname() {
    cout << "Plugboard" << endl;
}
