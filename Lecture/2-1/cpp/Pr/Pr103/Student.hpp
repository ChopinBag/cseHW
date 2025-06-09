#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "my_make_unique.hpp"
#include <string>
#include <iostream>

using namespace std;

class Student {
    private:
        string name_;
        int year_;
    public:
        Student() = default;

        // lvalue
        Student(string& n)
            :name_{n},year_{1}{}
        
        // rvalue
        Student(string&& n)
            :name_{n},year_{1}{}

        // lvalue
        Student(string& n, int y)
            :name_{n}, year_{y}{}

        // rvalue
        Student(string&& n, int y)
            :name_{n}, year_{y}{}

        friend ostream& operator<<(ostream& os, const Student& s){
            os << s.name_ << " " << s.year_;
        };
};

#endif