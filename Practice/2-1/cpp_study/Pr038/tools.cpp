//Implement your code

#include "tools.h"
#include <sstream>
#include <iostream>
using namespace std;


void std_newline(std::string &text){
    string s;
    stringstream ss(text);
    bool prev_r = false;

    while(ss >> s){
        if (s[0] == '\r') {
            prev_r = true;
            s.erase(s.begin(), s.end());
            s.push_back('\n');
        }
        if((s[0] == '\n')&& prev_r) {

        }
    }

}

std::string show_chars(const std::string &text){

}

std::string diff_output(const std::string &expected, const std::string &actual){

}