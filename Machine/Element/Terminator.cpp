#include "Terminator.hpp"

Terminator::Terminator(shared_ptr<Instance> instance): Element(instance) {
    this->instance = instance;
}

int Terminator::pass(int x){
    cout << "- - - - -" << endl;
    printname();
    instance->changeVerse();
    cout << "Value: " << x << endl;
    return x;
}

int Terminator::getInstance(int x){
    return 0;
}

void Terminator::printname() {
    cout << "Terminator" << endl;
}
