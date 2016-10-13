#include "Starter.hpp"

Starter::Starter(shared_ptr<Instance> instance): Element(instance) {
    //Hey! What a nice starter!
}

int Starter::pass(int x){
    return this->forward()->pass(x);
}

int Starter::getInstance(int x){
    return 0;
}
