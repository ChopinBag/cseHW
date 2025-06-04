#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <initializer_list>

class Matrix {
private:
    int* data;
    size_t row;
    size_t col;

public:
    
    
    Matrix(size_t r = 0, size_t c = 0) 
    : row(r), col(c) {
        if (r == 0 || c == 0) {
            this->row = 0; 
            this->col = 0;
            data = nullptr;
        } else {
            data = new int[this->row * this->col](); 
        }
    }

    Matrix(std::initializer_list<std::initializer_list<int>>);

    
    Matrix(const Matrix&);

    Matrix& operator=(const Matrix&);

    ~Matrix();

    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const Matrix&) const;
    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;


    friend std::ostream& operator<<(std::ostream&, const Matrix&);

    [[nodiscard]] Matrix inverse() const;
};

#endif 