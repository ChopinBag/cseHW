#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        Person() = default;
        Person(const string& theName)
        : name{theName}
        {
            cout << "Person is constructed!" << endl;
        };

        ~Person(){
            cout << "Person is destructed!" << endl;
        }
        void print(){
            cout << "Person Name: " << name << endl;
        };

    private:
        string name;
};


class Student : public Person{
    public:
        Student() = default;
        Student(const string& theName, string theSchoolName)
        : name{theName}, schoolName{theSchoolName}
        {
            cout << "Person is constructed!" << endl;
            cout << "Student is constructed!" << endl;
        }
        void print(){
            cout << "Person Name: " << name << endl;
            cout << "School Name: " << schoolName << endl;
        };
        ~Student(){
            cout << "Student is destructed!" << endl;
        }
    private:
        string name;
        string schoolName;
};

int main() {
    Person p1{"Park"};
    p1.print();

    Student s1 {"Kim", "PNU"};
    s1.print();

    return 0;
}