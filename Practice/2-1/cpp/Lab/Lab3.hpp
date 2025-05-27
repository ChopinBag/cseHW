#ifndef LAB3_HPP
#define LAB3_HPP

#include <iostream>
#include <string>

using namespace std;
class Person {
    public:
        int grade_;
        string name_;
        Person(int g=-1, string n=" ", string h=" ", int ht = -1)
        : grade_{g}, name_{n}, hobby_{h}, height_{ht}
        {
            cout << "Person constructed" << endl;
        };

        ~Person(){
            cout << "Person destructed" << endl;
        };
    private:
        string hobby_;
    protected:
        int height_;
};

class Student : public Person{
    public:
        int student_number_;
        Student(Person p){};
        
        Student(int sn=0)
        : Person(), student_number_{sn}
        {
            cout << "Student constructed" << endl;
        }

        ~Student(){
            cout << "Student destructed" << endl;
        }
};

#endif