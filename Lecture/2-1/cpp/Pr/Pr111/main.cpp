#include <iostream>
#include "Array.hpp"

// Implement your code
using namespace std;

int main() {
    Array<int> arr(5);
    try{
        arr.at(0) = 1;
        arr.at(1) = 2;
        arr.at(2) = 3;
        arr.at(3) = 4;
        arr.at(4) = 5;
        arr.at(5) = 6;
        
    } catch(const out_of_range& e) {
        std::cout << e.what() << std::endl;
    };

    return 0;
}