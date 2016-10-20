#ifndef PLUGBOARD_HPP
#define PLUGBOOARD_HPP

#include "../../Util.hpp"
#include "../Instance.hpp"
#include "Mapper.hpp"
#include "Element.hpp"

class Plugboard: public Element{
public:
    Plugboard(shared_ptr<Instance>);

    //Encripts the given input int.
    int getInstance(int);

    //Sets the vector<int> used by the Plugboard for encription.
    void setMap(vector<int>);

    void printname();

private:
    shared_ptr<Mapper> map;
};

#endif
