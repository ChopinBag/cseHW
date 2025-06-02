#include "Employee.hpp"
#include <utility>

using namespace std;

// Implement your code
Employee::Employee(string name, int salary)
: name_{name}, salary_{salary}
{};

string Employee::getName() const{
    return name_;
};
int Employee::getId() const{
    return id_;
};
int Employee::getSalary() const{
    return salary_;
};

double Employee::calculatePay() const{
    return salary_ / 12;
};
void Employee::printDetails(std::ostream& os) const{};