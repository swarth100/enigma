#include "Terminator.hpp"

Terminator::Terminator(shared_ptr<Instance> instance): Element(instance) {
    //Hey! What a nice terminator!
}

int Terminator::pass(int x){
    return x;
}

int Terminator::getInstance(int x){
    return 0;
}
