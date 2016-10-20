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

//Redefine mod to work as expected with negative values
int mod(int, int);

//Given a file PATH opens up the file to parse the input
//The input is returned as a vector<int> correspondant to the format of the file
vector<int> parse(string);

#endif
