#include "Mapper.hpp"

Mapper::Mapper() {
    mapping.reserve(26);

    for (int i = 0; i < (int) mapping.size(); i ++) {
        mapping[i] = 0;
    }
}

int Mapper::getMappedInt(int x) {
    return mod((x + mapping[x]), 26);
}

void Mapper::populateForwardRotor(vector<int> vector) {
    for (int i = 0; i < (int) mapping.size(); i ++) {
        mapping[i] = mod((vector[i] - mapping[i]), 26);
    }
}

void Mapper::populateBackwardRotor(vector<int> vector) {
    for (int i = 0; i < (int) mapping.size(); i ++) {
        mapping[vector[i]] = mod((mapping[i] - vector[i]), 26);
    }
}

void Mapper::populatePlugboard(vector<int> vector) {
    for (int i = 0; i < (int) vector.size(); i += 2) {
        mapping[i] = mod((vector[i] - vector[i+1]), 26);
        mapping[i+1] = mod((vector[i+1] - vector[i]), 26);
    }
}

void Mapper::populateReflector() {
    for (int i = 0; i < (int) mapping.size(); i ++) {
        mapping[i] = 13;
    }
}
