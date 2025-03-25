#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int countCharacter(const string& str, char ch) {
    auto dup_str = str;
    int cnt = 0;
    while(dup_str.find(ch) != string::npos){
        dup_str.erase(dup_str.find(ch), 1);
        cnt++;
    }
    return cnt;
}


void toUpperCase(string& str) {
    for (char &c : str){
      c = toupper(c);
    }
    return;
}



bool startsWith(const string_view str, const string_view prefix) {
    auto pfx_size = prefix.size();
    for (auto i=0; i < pfx_size; ++i){
        if (str[i] != prefix[i]){
          return false;
          }
    }
      return true;
}



int main() {
    vector<string> words = {"hello", "world", "example"};
    char characterToCount = 'l';

    for (const auto& word : words) {
        cout << "Count of '" << characterToCount << "' in \"" << word << "\": "
                  << countCharacter(word, characterToCount) << endl;
    }

    cout << endl;

    for (auto& word : words) {
        toUpperCase(word);
        cout << "Modified string: " << word << endl;
    }

    cout << endl;

    string_view prefix = "EX";

    for (const auto& word : words) {
        cout << "Does \"" << word << "\" start with '" << prefix << "'? "
                  << (startsWith(word, prefix) ? "Yes" : "No") << endl;
    }
    return 0;

}