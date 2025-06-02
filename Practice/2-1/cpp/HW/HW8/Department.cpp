#include "Department.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

explicit Department::Department(std::string name){};
const std::string& Department::getName() const{
    return name_;
};

void Department::setManager(std::unique_ptr<Manager> manager){
    manager_ = move(manager);
};

void Department::addEmployee(std::unique_ptr<Employee> emp){};
unique_ptr<Employee> Department::removeEmployee(Employee* emp){};
void Department::printDetails(std::ostream& os) const{};