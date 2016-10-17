#ifndef MAPPER_HPP
#define MAPPER_HPP

#include "../../Util.hpp"

class Mapper{
public:
    Mapper();
    int getMappedInt(int);
    int getMappedIntRot(int, int);

    void populateForwardRotor(vector<int>);
    void populateBackwardRotor(vector<int>);
    void populatePlugboard(vector<int>);
    void populateReflector();

private:
    vector<int> mapping;

    //int const MAX_ALPHABET = 26;
};

#endif
