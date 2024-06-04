#include "bracket.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string testCases[] = {"()[]{}", "([{}])", "(]", "([)]", "{[()]}[", "", "(", ")", "([]"};

    cout << "Testing stachMethodVerify:" << endl;
    for (const string &test : testCases) {
        cout << "Input: " << test << " -> " << (stackMethodVerify(&test) ? "Valid" : "Invalid") << endl;
    }

    cout << "\nTesting stachMethodVerifyDefault:" << endl;
    for (const string &test : testCases) {
        cout << "Input: " << test << " -> " << (stackMethodVerifyDefault(&test) ? "Valid" : "Invalid") << endl;
    }

    cout << "\nTesting regexValidBrackets:" << endl;
    for (const string &test : testCases) {
        cout << "Input: " << test << " -> " << (regexValidBrackets(&test) ? "Valid" : "Invalid") << endl;
    }

    cout << "\nTesting validateString:" << endl;
    for (const string &test : testCases) {
        cout << "Input: " << test << " -> " << (validateString(&test) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}