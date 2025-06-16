#include <iostream>
#include <fstream>

// Implement your code

using namespace std;
int main() {
    //예외 문제 나오면 그냥 main 시작하자마자 try catch 쓰자.
    try{
        std::ifstream fin;
        fin.exceptions(ios_base::failbit | ios_base::badbit);
        fin.open("input.txt"); // This will not throw an exception even if file is missing
        } catch(ios_base::failure& e){
        std::cerr << e.what() << std::endl;
    }

    try{
        std::ofstream fout;
        fout.exceptions(ios_base::failbit | ios_base::badbit);
        fout.open("config/config.ini"); // Will fail silently
        fout << "This is an example for the exception in C++!" << std::endl;
    } catch(ios_base::failure& e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}