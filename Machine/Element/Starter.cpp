#include "Starter.hpp"

Starter::Starter(shared_ptr<Instance> instance): Element(instance) {
}

int Starter::getInstance(int x){
    return x;
}

void Starter::printname() {
    cout << "Starter" << endl;
}
