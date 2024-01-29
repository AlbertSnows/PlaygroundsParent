#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
vector<string> splitString(const string input, char delimiter) {
    vector<string> tokens;
    stringstream tokenStream(input);
    string token;

    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}