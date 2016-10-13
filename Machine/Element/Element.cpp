#include "Element.hpp"

Element::Element(shared_ptr<Instance> instance) {
    this->instance = instance;
}

shared_ptr<Element> Element::forward() {
    return this->next;
}

void Element::setNext(shared_ptr<Element> element) {
    this->next = element;
}

int Element::pass(int x) {
    return getInstance(x);
}
