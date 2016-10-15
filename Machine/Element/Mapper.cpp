#include "Mapper.hpp"

Mapper::Mapper() {
    mapping.reserve(MAX_ALPHABET);

    for (int i = 0; i < MAX_ALPHABET; i ++) {
        mapping[i] = 0;
    }
}

int Mapper::getMappedInt(int x) {
    return mod((x + mapping[x]), MAX_ALPHABET);
}

int Mapper::getMappedIntRot(int x, int rotation) {
    return mod((x + mapping[mod(x+rotation, MAX_ALPHABET)]), MAX_ALPHABET);
}

void Mapper::populateForwardRotor(vector<int> vector) {
    for (int i = 0; i < MAX_ALPHABET; i ++) {
        mapping[vector[i]] = mod((vector[vector[i]] - vector[i]), MAX_ALPHABET);
    }
}

void Mapper::populateBackwardRotor(vector<int> vector) {
    for (int i = 0; i < MAX_ALPHABET; i ++) {
        mapping[vector[vector[i]]] = mod((vector[i] - vector[vector[i]]),
                                                                  MAX_ALPHABET);
    }
}

void Mapper::populatePlugboard(vector<int> vector) {
    for (int i = 0; i < (int) vector.size(); i += 2) {
        mapping[vector[i]] = mod((vector[i+1] - vector[i]), MAX_ALPHABET);
        mapping[vector[i+1]] = mod((vector[i] - vector[i+1]), MAX_ALPHABET);
    }
}

void Mapper::populateReflector() {
    for (int i = 0; i < MAX_ALPHABET; i ++) {
        mapping[i] = 13;
    }
}
