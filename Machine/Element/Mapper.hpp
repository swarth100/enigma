#ifndef MAPPER_HPP
#define MAPPER_HPP

#include "../../Util.h"

class Mapper{
public:
    Mapper();
    int getMappedInt(int);

    void populateRotor (vector<int>);
    void populatePlugboard (vector<int>);

private:
    int const MAX_ALPHABET = 26;
    vector<int> mapping;
};

#endif
