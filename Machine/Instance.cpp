#include "Instance.hpp"

Instance::Instance() {
    this->verse = Status::FORWARD;
}

void Instance::changeVerse() {
    switch (verse) {
        case Status::FORWARD:
            verse = Status::BACKWARD;
            return;
        default:
            verse = Status::FORWARD;
            return;
    }
}

Instance::Status Instance::getVerse() {
    return verse;
    //BOB
    //BOBBY
}
