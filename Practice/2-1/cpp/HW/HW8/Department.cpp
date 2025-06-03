#include "Department.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Department::Department(std::string name) 
: name_(std::move(name)) {}

const std::string& Department::getName() const{
    return name_;
};

void Department::setManager(std::unique_ptr<Manager> manager){
    manager_ = move(manager);
};

void Department::addEmployee(std::unique_ptr<Employee> emp){
    employees_.push_back(move(emp));
};
unique_ptr<Employee> Department::removeEmployee(Employee* emp){
    for (auto it = employees_.begin(); it != employees_.end(); ++it) {
    if (it->get() == emp) {
        auto ret = std::move(*it);
        employees_.erase(it);
        return ret;
        }
    }
    return nullptr;

};

void Department::printDetails(std::ostream& os) const{
    cout << name_ << endl;
    if (manager_) {
        os << "\t|---Manager: " << manager_->getName() << " " << manager_->getId() << " (Annual: " << manager_->getSalary()
        << ", Monthly Pay: " << manager_->calculatePay() << ")" << std::endl;
    }
    for (const auto& it : employees_){
        it->printDetails(os);
    }
};