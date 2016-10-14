#include "Util.h"

#include "Machine/Machine.hpp"

using namespace std;

int main(int argc, char **argv)
{
    //cout << "C++ Enigma Machine" << endl;

    shared_ptr<Machine> enigma = make_shared<Machine>();

    string input = "";
    string output;

    //cout << "Input: " << endl;
    cin >> input;

    output = input;

    int argInt = 1;
    int maxArgc = argc-1;

    enigma->addPlugboard(parse(argv[maxArgc]));

    while (argInt < maxArgc) {
        enigma->addRotor(parse(argv[argInt]));
        argInt ++;
    }

    enigma->assemble();

    int decIn;
    int index = 0;

    while(input[index] != '\0') {
        decIn = input[index] - 'A';
        output[index] = (enigma->simulate(decIn) + 'A');
        index++;
    }

    cout << output << endl;

    return 0;
}
