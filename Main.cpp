#include "Util.h"

#include "Machine/Machine.hpp"

using namespace std;

int main(int argc, char **argv)
{
    //cout << "C++ Enigma Machine" << endl;

    shared_ptr<Machine> enigma = make_shared<Machine>();

    string input = "";
    string tmp = "";
    string output;

    //cout << "Input: " << endl;
    while (getline(cin, tmp)) {
        input += tmp;
        input += "\n";
    }

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
    //cout << input << endl;

    while(input[index] != '\0') {
        decIn = input[index] - 'A';
        output[index] = (enigma->simulate(decIn) + 'A');
        //cout << input[index] << output[index] << endl;
        index++;
    }

    cout << output << endl;

    return 0;
}
