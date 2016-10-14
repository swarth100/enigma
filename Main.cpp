#include "Util.h"

#include "Machine/Machine.hpp"

using namespace std;

int main(int argc, char **argv)
{
    cout << "C++ Enigma Machine" << endl;

    shared_ptr<Machine> enigma = make_shared<Machine>();

    char* input = (char*) malloc(sizeof(char));
    char* output = (char*) malloc(sizeof(char));

    cout << "Input: " << endl;
    cin >> input;

    strcpy(output, input);

    //enigma->addPlugboard(parse("plugboards/V.pb"));
    enigma->addRotor(parse("rotors/II.rot"));

    enigma->assemble();

    int decIn;
    int index = 0;

    while(input[index] != '\0') {
        decIn = input[index] - 'a';
        output[index] = (enigma->simulate(decIn) + 'a');
        index++;
    }

    cout << "Result: " << output << endl;

    free (input);
    free (output);

    return 0;
}
