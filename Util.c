#include "Util.h"

int MAX_ALPHABET = 26;

int mod(int num, int base) {
  int res = num % base;
  return res >= 0 ? res : res + base;
}

vector<int> parse(string path) {
    vector<int> result;
    result.reserve(MAX_ALPHABET);

    const char* filePath = path.c_str();
    ifstream inStream(filePath);

    //Save standard input
    streambuf *cinBuffer = cin.rdbuf();
    cin.rdbuf(inStream.rdbuf());

    string delimiter = " ";
    size_t pos;

    string str;
    string token;
    int intIn;

    getline(cin, str);
    cout << "- - - - -" << endl;
    cout << str << endl;

    while ((pos = str.find(delimiter)) != string::npos) {
        token = str.substr(0, pos);

        intIn = stoi(token);
        result.push_back(intIn);

        str.erase(0, pos + delimiter.length());
    }
    intIn = stoi(str);
    result.push_back(intIn);

    //Reset to standard Input
    cin.rdbuf(cinBuffer);

    cout << "- - - - -" << endl;

    return result;
}
