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
    // Implement your code
    Matrix() = default;
    Matrix(size_t r, size_t c)
    : row{r}, col{c} 
    {};

    Matrix(std::initializer_list<std::initializer_list<int>>);
    //deep copy
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);
    ~Matrix();

    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const Matrix&) const;
    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;
    
    Matrix inverse() const;

    friend std::ostream& operator<<(std::ostream&, const Matrix&);

    [[nodiscard]] Matrix inverse() const;
};

#endif // MATRIX_H