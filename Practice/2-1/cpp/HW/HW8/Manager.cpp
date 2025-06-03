#include "Manager.hpp"

// Implement your code
using namespace std;

Manager::Manager(std::string name, int salary)
: Employee(move(name), salary)
{};

double Manager::calculatePay() const {
    return (getSalary() * 1.1) / 12;
};