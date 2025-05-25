#include "Matrix.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector> // For inverse calculation temporary storage if needed, though not used in this fix

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
                delete[] data; // Should not be needed here as data is not allocated yet
                throw std::out_of_range("Initializer list has inconsistent column sizes (some empty, some not).");
            }
        }
        data = nullptr;
    } else {
        col = first_row_it->size();
        data = new int[row * col](); // Zero-initialize
        int* current_ptr = data;
        for (const auto& r_list : init) {
            if (r_list.size() != col) {
                delete[] data;
                data = nullptr;
                throw std::out_of_range("Initializer list has inconsistent column sizes.");
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
        this->row = 0; // Normalize
        this->col = 0;
    } else {
        this->data = new int[this->row * this->col](); // Allocate and zero-initialize
        if (m.data) { // If source data exists, copy it
            std::copy(m.data, m.data + (this->row * this->col), this->data);
        }
        // If m.data was null (and m.row/col were not 0, an inconsistent state for m),
        // this->data is now safely zero-initialized.
    }
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this == &m) {
        return *this;
    }

    delete[] data; // Delete old data

    this->row = m.row;
    this->col = m.col;

    if (this->row == 0 || this->col == 0) {
        this->data = nullptr;
        this->row = 0; // Normalize
        this->col = 0;
    } else {
        this->data = new int[this->row * this->col](); // Allocate and zero-initialize
        if (m.data) {
            std::copy(m.data, m.data + (this->row * this->col), this->data);
        }
        // If m.data was null, 'this->data' remains zero-initialized.
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
    Matrix result(row, col); // Data is allocated and zero-initialized by Matrix(size_t, size_t)
    for (size_t i = 0; i < row * col; ++i) {
        result.data[i] = this->data[i] + m.data[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& m) const {
    if (this->row != m.row || this->col != m.col) {
        return Matrix();
    }
    Matrix result(row, col); // Data is allocated and zero-initialized
    for (size_t i = 0; i < row * col; ++i) {
        result.data[i] = this->data[i] - m.data[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& m) const {
    if (this->col != m.row) {
        return Matrix();
    }
    Matrix result(this->row, m.col); // Data is allocated and zero-initialized
    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < m.col; ++j) {
            // result.data[i * m.col + j] is already 0
            for (size_t k = 0; k < this->col; ++k) { // this->col is m.row
                if(this->data && m.data) { // Ensure data pointers are not null before dereferencing
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
    if (this->row != m.row || this->col != m.col) {
        return false;
    }
    if (this->data == m.data) return true; // Both nullptr or same memory
    if (!this->data || !m.data) { // One is nullptr, the other isn't (and dimensions matched)
        // This case implies one is empty and the other is not, despite same non-zero dims.
        // Or both are 0-dim, in which case data should be nullptr and caught by previous line.
        // If dims are non-zero, one having data and other not is unequal.
        return false;
    }
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
    Matrix result(row, col); // Data allocated and zero-initialized

    if (!data) return Matrix(); // Should not happen if row != 0

    if (row == 2) {
        long long det_ll = (long long)data[0] * data[3] - (long long)data[1] * data[2];
        if (det_ll == 0 || (det_ll != 1 && det_ll != -1)) {
            return Matrix(); // No integer inverse if det is 0 or not +/-1
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
            return Matrix(); // No integer inverse if det is 0 or not +/-1
        }
        int det = static_cast<int>(det_ll); // det is now 1 or -1

        // Adjoint matrix elements divided by determinant
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
        return Matrix(); // Not implemented for other sizes
    }
    return result;
}