#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>

using namespace std;

class Employee {
public:
    Employee()=default;
    Employee(string name, int salary) : name_(name), salary_(salary) {}
    virtual void print_report() const { 
        cout << "Name: " << name_ << endl;
        cout << "Salary: " << salary_ << endl;
        cout << "Years of service: " << years_of_service_ << endl;
        cout << "Performance score: " << performance_score_ << endl;
    }
    string get_name() const {
        return name_;
    }
protected:
    string name_;
    int salary_;
    int years_of_service_ = 0;
    int performance_score_ = 0;
};

class Manager : public Employee{
    public:
        string name_;
        int salary_;
        string department_;
        Manager(string name, int salary, string department)
        : name_{name}, salary_{salary}, department_{department}
        {}
        void set_goals(){cout << "Set goals for " << department_ << endl;}
    private:
        
};

class Programmer : public Employee{
    public:
        string name_;
        int salary_;
        string lang_;
        Programmer()=default;
        Programmer(string name, int salary, string lang)
        : name_{name}, salary_{salary}, lang_{lang}
        {};
        void write_code(){
            cout << "Writing code in " << lang_ << endl;
            performance_score_ += 10;
        }
    private:

};

class Salesperson : public Employee{
    public:
        string name_;
        int salary_;
        int revenue_;
        Salesperson(string name, int salary, int revenue)
        : name_{name}, salary_{salary}, revenue_{revenue}
        {};
        void sell(){
            cout << "Selling products, generated " << revenue_ << " in revenue" << endl;
            performance_score_ += 20;
        }
    private:
        
};
#endif