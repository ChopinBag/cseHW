#include "Matrix.hpp"
#include <algorithm>

//Implement your code
using namespace std;

Matrix::Matrix(std::initializer_list<std::initializer_list<int>>){};
//deep copy
Matrix::Matrix(const Matrix&){};
Matrix& Matrix::operator=(const Matrix&){};
Matrix::~Matrix(){};

Matrix Matrix::operator+(const Matrix&) const{};
Matrix Matrix::operator-(const Matrix&) const{};
Matrix Matrix::operator*(const Matrix&) const{};
bool Matrix::operator==(const Matrix&) const{};
bool Matrix::operator!=(const Matrix&) const{};

Matrix Matrix::inverse() const{};

Matrix Matrix::inverse() const {
    //Implement your code
}
