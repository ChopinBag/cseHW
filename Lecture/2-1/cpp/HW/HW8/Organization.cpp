#include "Organization.hpp"
#include <iostream>
#include <algorithm>

// Implement your code

using namespace std;

Organization::Organization(std::string name)
    : name_(std::move(name)) {}

void Organization::addDept(unique_ptr<Department> dept) {
    departments_.push_back(move(dept));
};

void Organization::addEmpToDept(Department* dept, unique_ptr<Employee> emp) {
    dept->addEmployee(move(emp));
};

void Organization::setDeptManager(Department* dept, unique_ptr<Manager> manager) {
    dept->setManager(move(manager));
};
bool Organization::moveEmp(Department* from, Department* to, Employee* emp) {
    if (!from || !to || !emp) return false;
    auto removedEmp = from->removeEmployee(emp);
    to->addEmployee(move(removedEmp));
    return true;
};

void Organization::print() const {
    cout << "Organization: " << name_ << endl;
    for(const auto& it1 : departments_){
        it1->printDetails(cout);
    }
};