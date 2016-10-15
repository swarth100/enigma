#include "Terminator.hpp"

Terminator::Terminator(shared_ptr<Instance> instance): Element(instance) {
}

int Terminator::pass(int x){
    instance->changeVerse();
    return x;
}

int Terminator::getInstance(int x){
    return 0;
}

void Terminator::printname() {
    cout << "Terminator" << endl;
}
