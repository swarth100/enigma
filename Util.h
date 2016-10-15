#ifndef UTIL_H
#define UTIL_H

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <numeric>

using namespace std;

int const MAX_ALPHABET = 26;
char const BASE_CHAR = 'A';

int mod(int, int);

vector<int> parse(string);

#endif
