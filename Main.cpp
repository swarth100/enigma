#include "Util.h"

#include "Machine/Machine.hpp"

using namespace std;

int main(int argc, char **argv)
{
    cout << "C++ Enigma Machine" << endl;

    shared_ptr<Machine> enigma = make_shared<Machine>();

    int input;
    int result;

    cout << "Input: " << endl;
    cin >> input;

    enigma->addPlugboard(parse("plugboards/V.pb"));

    enigma->assemble();

    result = enigma->simulate(input);

    cout << "Result: " << result << endl;

    return 0;
}
