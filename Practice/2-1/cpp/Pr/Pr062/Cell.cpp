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

bool Cell::isNumeric() const{
    if(this->type_==CellType::INT || this->type_==CellType::DOUBLE)return true;
    else return false;
}

bool Cell::isString() const{
    if(this->type_==CellType::STRING)return true;
    else return false;
}

double Cell::getNumericValue() const{
    if (isString())return 0.0;
    else if (this->type_==CellType::INT) return intVal_;
    else return doubleVal_;
}

string Cell::toString() const{
    if(isString())return this->stringVal_;
    else if(this->type_==CellType::INT){
        return to_string(this->intVal_);
    }else{
        stringstream ss;
        ss << fixed << setprecision(1);
        ss << to_string(this->doubleVal_);
        return ss.str();
    }
}
