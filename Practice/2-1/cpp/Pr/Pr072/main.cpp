#include <iostream>
#include <string>
#include <map>
#include <initializer_list>
#include <utility>
using namespace std;

class Phonebook {
    map<string, int> contacts;
public:
    Phonebook(initializer_list <pair<string, int>> lst) {
        //생성자를 구현하세요!
        for(auto it=lst.begin(); it != lst.end(); ++it){
            contacts[it->first] = it->second;
        }
        // for_each(lst.begin(),lst.end(), [this](auto p){contacts.insert(p);});
        // for(const auto& p : contact`s){contacts[p.first]=p.second;}
        
    }
    void print() const {
        //멤버 함수를 구현하세요!
    for (auto it = contacts.begin(); it != contacts.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }   
    }
};



int main() {
    Phonebook p = {{"Kim", 24}, {"Lee", 21}};
    p.print();
    return 0;
}

