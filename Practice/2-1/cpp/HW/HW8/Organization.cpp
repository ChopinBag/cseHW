#include "Organization.hpp"
#include <iostream>
#include <algorithm>

// Implement your code
using namespace std;

void Organization::addDept(unique_ptr<Department> dept) {};
void Organization::addEmpToDept(Department* dept, unique_ptr<Employee> emp) {};
void Organization::setDeptManager(Department* dept, unique_ptr<Manager> manager) {};
bool Organization::moveEmp(Department* from, Department* to, Employee* emp) {};
void Organization::print() const {};