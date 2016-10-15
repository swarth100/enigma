#include "Util.h"

#include "Machine/Machine.hpp"

using namespace std;

int main(int argc, char **argv)
{
    //cout << "C++ Enigma Machine" << endl;

    shared_ptr<Machine> enigma = make_shared<Machine>();

    int argInt = 1;
    int maxArgc = argc-1;

    enigma->addPlugboard(parse(argv[maxArgc]));

    while (argInt < maxArgc) {
        enigma->addRotor(parse(argv[argInt]));
        argInt ++;
    }

    enigma->assemble();

    int index = 0;

    char input;

    while(cin>>input) {
        cout << enigma->simulate(input);
        index++;
    }

    cout << endl;

    return 0;
}
