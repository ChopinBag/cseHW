#include "Cell.h"
#include <iomanip>
#include <sstream>


Cell::Cell() : type_{CellType::STRING}, stringVal_{""}, intVal_{0}, doubleVal_{0.0} {}


// Implement your code


using namespace std;

Cell::Cell(const string& val) // plato IDE 에서는 & 떼어내야 함.
    : type_(CellType::STRING),stringVal_(val), intVal_(0),doubleVal_(0.0)
{}

Cell::Cell(int val)
    :type_{CellType::INT}, stringVal_{""}, intVal_{val}, doubleVal_{0.0}
{}

Cell::Cell(double val)
    : type_{CellType::DOUBLE}, stringVal_{""}, intVal_{0}, doubleVal_{val} 
{}

bool Cell::isNumeric() const {
    return type_ == CellType::INT || type_ == CellType::DOUBLE;
}

bool Cell::isString() const {
    return type_ == CellType::STRING;
}

double Cell::getNumericValue() const {
    if (isString()) return 0.0;
    if (type_ == CellType::INT) return intVal_;
    return doubleVal_;
}

string Cell::toString() const {
    if (isString()) return stringVal_;
    if (type_ == CellType::INT) return to_string(intVal_);
    stringstream ss;
    ss << fixed << setprecision(1) << doubleVal_;
    return ss.str();
}
