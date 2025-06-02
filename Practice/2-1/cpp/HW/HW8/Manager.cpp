#include "Manager.hpp"

// Implement your code
using namespace std;

// Manager::Manager(std::string name, int salary){};

double Manager::calculatePay() const {
    return getSalary() / 12;
};