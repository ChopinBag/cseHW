#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <initializer_list>
#include <stdexcept> // std::out_of_range 사용을 위해 추가

class Matrix {
private:
    int* data;
    size_t row;
    size_t col;

public:
    // Implement your code
    // Matrix() = default;
    Matrix(size_t r = 0, size_t c = 0) // 기본 인자 추가 및 구현 수정
    : row(r), col(c) {
        if (r == 0 || c == 0) {
            this->row = 0; // 일관성을 위해 둘 다 0으로 설정
            this->col = 0;
            data = nullptr;
        } else {
            data = new int[this->row * this->col](); // 메모리 할당 및 0으로 초기화
        }
    }

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


    friend std::ostream& operator<<(std::ostream&, const Matrix&);

    [[nodiscard]] Matrix inverse() const;
};

#endif // MATRIX_H