#include "word_manager.h"
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

void findWord(const map<string, size_t>& words, const string& rawWord) {
    string changedWord;
    for (auto i:rawWord) {
        changedWord += tolower(i);
    }
    auto it = words.find(changedWord);
    if (it != words.end()) {
        cout << changedWord << ": " << it->second << endl;
    } else {
        cout << changedWord << " not found." << endl;
    }
}

void updateWord(map<string, size_t>& words, const string& rawWord, size_t value) {
    string changedWord;
    for (auto i:rawWord) {
        changedWord += tolower(i);
    }
    auto it = words.find(changedWord);
    if (it != words.end()) {
        it->second = value;
        cout << "Updated: " << changedWord << ": " << it->second << endl;
    } else {
        cout << changedWord << " not found." << endl;
    }
}

void deleteWord(map<string, size_t>& words, const string& rawWord) {
    string changedWord;
    for (auto i:rawWord) {
        changedWord += tolower(i);
    }
    auto it = words.find(changedWord);
    if (it != words.end()) {
        words.erase(it);
        cout << "Deleted: " << changedWord << endl;
    } else {
        cout << changedWord << " not found." << endl;
    }
}

void printWords(const map<string, size_t>& words) {
    cout << "Word List: ";
    for(auto it : words) {
        cout << it.first << ": " << it.second << " ";
    }
    cout << endl;

}
