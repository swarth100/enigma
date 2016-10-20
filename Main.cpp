#include "Util.hpp"

#include "Machine/Machine.hpp"

using namespace std;

//General Design:
//
//       main ----> Machine ----> Element -----> Instance
//                                   ^
//                                   |
//                                   |
//           +------------+----------+-----------+---------------+
//           |            |          |           |               |
//        Starter    Plugboard     Rotor     Reflector      Terminator
//                        |          |           |
//                        +----------+-----------+
//                                   |
//                                   |
//                                   V
//                                Mapper
//
//Machine:
//    Provides an interface the user can use to create an enigma machine with
//    a number of given configuration files.
//    Subsequent input updates the machine rotating rotors when necessary.
//
//Element:
//    A Machine is made up of Elements.
//    In order to resemble reality each Element will only ever see the elements
//    previous or next to themselves.
//    The Machine's input is passed into a Starter and makes its way through
//    till when it reaches a Terminator and thus returns.
//
//Starter:
//    First Element in the enigma machine.
//    The only Element the Machine class is aware about (just like the keyboard
//    would be in a real life version).
//
//Terminator:
//    Last Element in the enigma machine.
//    Returns the encripted value of the input char (simulates the lights
//    lighing up in real life).
//
//Plugboard:
//    Maps couples of characters to eachother.
//
//Rotor:
//    Maps characters to eachother according to a given configuration.
//
//Reflector:
//    Maps characters with a fixed 13 offset.
//
//Mapper:
//    Used by the Plugboard, Rotor and Reflector classes, the Mapper is
//    initialised with a configuration and provides common methods to retrieve
//    the mapped chars of the Elements at any given time.
//
//Instance:
//    Provides a number of global parameters all Elements of the Machine would
//    be aware of during an encription.
//
//------------------------------------------------------------------------------
//
//General notes on the Design:
//
//-I tried to rectreate enigma as faithfull as I could be to reality. This means
// that encription occurs recursively making our way through the Elements, just
// like the electrical impulses make their way through the actual machine.
//-Elements only ever knows that another Element precedes or follows them.
//-No Element has knowledge of the Machine. They just share common knowledge of
// Instance methods and/or variables.
//-This design is 100% customizable. One could have as many plugboards as he
// wished and in any possible combination with rotors. Due to the restrictions
// of the spec it currently is forced to work with the given template.

int main(int argc, char **argv)
{
    shared_ptr<Machine> enigma = make_shared<Machine>(argc, argv);

    char input;

    while(cin>>input) {
        cout << enigma->simulate(input);
    }

    return 0;
}
