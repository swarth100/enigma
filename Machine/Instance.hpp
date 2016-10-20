#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include "../Util.hpp"

//Provides a number of globally known "states" between all Machine Elements
class Instance{
public:
    Instance();
    enum class Status {FORWARD, BACKWARD};

    //Invers the verse the Elements are using to call the next() Element.
    //Used by Reflector and Terminator Elements.
    //E.g.
    //element->next = a;
    //element->previous = b;
    //    $ element->forward()
    //    > a
    //    $ changeVerse()
    //    $ element->forward()
    //    > b
    void changeVerse();
    //Getter for the verse of the Machine.
    Status getVerse();

private:
    Status verse;
};

#endif
