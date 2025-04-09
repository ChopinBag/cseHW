#include "word_input.h"
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

void processInput(map<string, size_t>& words) {
    string input;
    while (getline(cin, input) && input != "^^") {
        istringstream iss(input);
        string word;
        while ((iss >> word)) {
            string ret = "";
            for (char c: word) {
                if('a'<='c'&&c<='z') ret +=c;
                else if('A'<=c && c<='Z') ret += tolower(c);
            }
            words[ret]++;
        }
    }
}
