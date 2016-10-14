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
    cout << "- - - - -" << endl;
    printname();
    /*if (next != NULL) {
        cout << "Next: ";
        next->printname();
    }
    if (previous != NULL) {
        cout << "Previous: ";
        previous->printname();
    } */

    cout << "Value: " << x << endl;

    //cout << "Value: " << this->getInstance(x) <<endl;
    return forward()->pass(this->getInstance(x));
}
