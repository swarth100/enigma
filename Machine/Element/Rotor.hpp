#ifndef ROTOR_HPP
#define ROTOR_HPP

#include "../../Util.hpp"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

//Rotor Element
class Rotor: public Element{
public:
    Rotor(shared_ptr<Instance>);

    //Encripts the given input int.
    int getInstance(int);

    //Sets the vector<int> used by the Rotor for encription.
    void setMap(vector<int>);

    void printname();

    //Sets the "next" Rotor.
    //Used on a Rotation cascade when a full revolution of a previous Rotor
    //causes the following one to turn as well.
    void setNextRotor(shared_ptr<Rotor>);
    shared_ptr<Rotor> getNextRotor();

    //Forces a rotation on the given Rotor.
    //Returns true if a full revolution occurs.
    bool rotate();

private:
    shared_ptr<Mapper> mapForward;
    shared_ptr<Mapper> mapBackward;
    shared_ptr<Rotor> nextRotor;

    int rotation;
};

#endif
