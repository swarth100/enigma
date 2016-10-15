#include "Element.hpp"

Element::Element(shared_ptr<Instance> instance) {
    this->instance = instance;
}

shared_ptr<Element> Element::forward() {
    if (instance->getVerse() == Instance::Status::FORWARD)
    {
        return this->next;
    } else {
        return this->previous;
    }
}

void Element::setNext(shared_ptr<Element> element) {
    this->next = element;
}

void Element::setPrevious(shared_ptr<Element> element) {
    this->previous = element;
}

int Element::pass(int x) {
    return forward()->pass(this->getInstance(x));
}
