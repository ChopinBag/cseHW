#include "Matrix.hpp"
#include <algorithm>

using namespace std;

Matrix::Matrix(std::initializer_list<std::initializer_list<int>> init) {
    row = init.size();
    if (row == 0) {
        col = 0;
        data = nullptr;
        return;
    }

    auto first_row_it = init.begin();
    if (first_row_it->size() == 0) {
        col = 0;
        for (const auto& r_list : init) {
            if (r_list.size() != 0) {
                delete[] data;
            }
        }
        data = nullptr;
    } else {
        col = first_row_it->size();
        data = new int[row * col](); 
        int* current_ptr = data;
        for (const auto& r_list : init) {
            if (r_list.size() != col) {
                delete[] data;
                data = nullptr;
            }
            current_ptr = std::copy(r_list.begin(), r_list.end(), current_ptr);
        }
    }
}

Matrix::Matrix(const Matrix& m) {
    this->row = m.row;
    this->col = m.col;
    if (this->row == 0 || this->col == 0) {
        this->data = nullptr;
        this->row = 0; 
        this->col = 0;
    } else {
        this->data = new int[this->row * this->col](); 
        if (m.data) { 
            std::copy(m.data, m.data + (this->row * this->col), this->data);
        }
        
        
    }
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this == &m) {
        return *this;
    }

    delete[] data; 

    this->row = m.row;
    this->col = m.col;

    if (this->row == 0 || this->col == 0) {
        this->data = nullptr;
        this->row = 0; 
        this->col = 0;
    } else {
        this->data = new int[this->row * this->col](); 
        if (m.data) {
            std::copy(m.data, m.data + (this->row * this->col), this->data);
        }
        
    }
    return *this;
}

Matrix::~Matrix() {
    delete[] data;
}

Matrix Matrix::operator+(const Matrix& m) const {
    if (this->row != m.row || this->col != m.col) {
        return Matrix();
    }
    Matrix result(row, col); 
    for (size_t i = 0; i < row * col; ++i) {
        result.data[i] = this->data[i] + m.data[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& m) const {
    if (this->row != m.row || this->col != m.col) {
        return Matrix();
    }
    Matrix result(row, col); 
    for (size_t i = 0; i < row * col; ++i) {
        result.data[i] = this->data[i] - m.data[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& m) const {
    if (this->col != m.row) {
        return Matrix();
    }
    Matrix result(this->row, m.col); 
    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < m.col; ++j) {
            
            for (size_t k = 0; k < this->col; ++k) { 
                if(this->data && m.data) { 
                    result.data[i * m.col + j] += this->data[i * this->col + k] * m.data[k * m.col + j];
                }
            }
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    if (m.data == nullptr || m.row == 0 || m.col == 0) {
        os << "| |" << std::endl;
        return os;
    }
    for (size_t i = 0; i < m.row; ++i) {
        os << "| ";
        for (size_t j = 0; j < m.col; ++j) {
            os << m.data[i * m.col + j] << (j == m.col - 1 ? "" : " ");
        }
        os << " |" << std::endl;
    }
    return os;
}

bool Matrix::operator==(const Matrix& m) const {
    if (this->row != m.row || this->col != m.col) return false;
    if (this->data == m.data) return true; 
    if (!this->data || !m.data) return false;
    for (size_t i = 0; i < row * col; ++i) {
        if (this->data[i] != m.data[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m) const {
    return !(*this == m);
}


Matrix Matrix::inverse() const {
    if (row != col || row == 0) {
        return Matrix();
    }
    Matrix result(row, col); 

    if (!data) return Matrix(); 

    if (row == 2) {
        long long det_ll = (long long)data[0] * data[3] - (long long)data[1] * data[2];
        if (det_ll == 0 || (det_ll != 1 && det_ll != -1)) {
            return Matrix(); 
        }
        int det = static_cast<int>(det_ll);
        result.data[0] = data[3] / det;
        result.data[1] = -data[1] / det;
        result.data[2] = -data[2] / det;
        result.data[3] = data[0] / det;
    } else if (row == 3) {
        long long det_ll = (long long)data[0] * (data[4] * data[8] - data[5] * data[7]) -
                           (long long)data[1] * (data[3] * data[8] - data[5] * data[6]) +
                           (long long)data[2] * (data[3] * data[7] - data[4] * data[6]);

        if (det_ll == 0 || (det_ll != 1 && det_ll != -1)) {
            return Matrix(); 
        }
        int det = static_cast<int>(det_ll); 

        
        result.data[0] = ((long long)data[4] * data[8] - (long long)data[5] * data[7]) / det;
        result.data[1] = ((long long)data[2] * data[7] - (long long)data[1] * data[8]) / det;
        result.data[2] = ((long long)data[1] * data[5] - (long long)data[2] * data[4]) / det;

        result.data[3] = ((long long)data[5] * data[6] - (long long)data[3] * data[8]) / det;
        result.data[4] = ((long long)data[0] * data[8] - (long long)data[2] * data[6]) / det;
        result.data[5] = ((long long)data[2] * data[3] - (long long)data[0] * data[5]) / det;

        result.data[6] = ((long long)data[3] * data[7] - (long long)data[4] * data[6]) / det;
        result.data[7] = ((long long)data[1] * data[6] - (long long)data[0] * data[7]) / det;
        result.data[8] = ((long long)data[0] * data[4] - (long long)data[1] * data[3]) / det;
    } else {
        return Matrix(); 
    }
    return result;
}