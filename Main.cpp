#include "Util.h"

#include "Machine/Machine.hpp"

using namespace std;

int main(int argc, char **argv)
{
    shared_ptr<Machine> enigma = make_shared<Machine>(argc, argv);

    char input;

    while(cin>>input) {
        cout << enigma->simulate(input);
    }

    return 0;
}
