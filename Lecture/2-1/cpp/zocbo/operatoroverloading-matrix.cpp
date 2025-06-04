#include <iostream>

using namespace std;

class Matrix {
	int** values;
	int row, column;
	
	void copyFrom(const Matrix& matrix) {
		row = matrix.row;
		column = matrix.column;
		values = new int*[matrix.row];
		
		for (int indexRow = 0; indexRow < row; indexRow++) {
			values[indexRow] = new int[column];
			for (int indexColumn = 0; indexColumn < column; indexColumn++) {
				values[indexRow][indexColumn] = matrix.values[indexRow][indexColumn];
			}
		}
	}
	void remove() {
		for (int indexRow = 0; indexRow < row; indexRow++) {
			delete[] values[indexRow];
		}
		delete[] values;
	}
public:
	Matrix(const int _row, const int _column) : row(_row), column(_column), values(new int*[_row]) {  
		for (int index = 0; index < row; index++) {
			values[index] = new int[column];
		}
	}

	Matrix(const Matrix& matrix) {
		copyFrom(matrix);
	}

	Matrix operator +(const Matrix& matrix) const {
		Matrix matrixResult(row, column);
		for (int indexRow = 0; indexRow < matrixResult.row; indexRow++) {
			for (int indexColumn = 0; indexColumn < matrixResult.column; indexColumn++) {
				matrixResult.values[indexRow][indexColumn] = this->values[indexRow][indexColumn] + matrix.values[indexRow][indexColumn] ;
			}
		}
		return matrixResult;                                                                                                                                                                                               
	}

	Matrix operator *(const int scalar) const {
		Matrix matrixResult(row, column);
		for (int indexRow = 0; indexRow < matrixResult.row; indexRow++) {
			for (int indexColumn = 0; indexColumn < matrixResult.column; indexColumn++) {
				matrixResult.values[indexRow][indexColumn] = this->values[indexRow][indexColumn] * scalar;
			}
		}
		return matrixResult;
	}

	Matrix& operator =(const Matrix& matrix) {
		remove();

		copyFrom(matrix);
		
		return *this;
	}

	
	~Matrix() {
		remove();
	}

	friend ostream& operator<<(ostream& os, const Matrix& matrix);

	friend istream& operator>>(istream& is, Matrix& matrix);
};

ostream& operator<<(ostream& os, const Matrix& matrix) {
	for (int indexRow = 0; indexRow < matrix.row; indexRow++) {
		for (int indexColumn = 0; indexColumn < matrix.column; indexColumn++) {
			os << matrix.values[indexRow][indexColumn] << '\t';
		}
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, Matrix& matrix) {
	for (int indexRow = 0; indexRow < matrix.row; indexRow++) {
		for (int indexColumn = 0; indexColumn < matrix.column; indexColumn++) {
			is >> matrix.values[indexRow][indexColumn];
		}
	}
	return is;
}

int main() {
	Matrix m1(2, 2), m2(2, 2);
	cin >> m1;
	cin >> m2;

	Matrix m3(m1 + m2);
	Matrix m4(2, 2);

	m4 = m3 * 10;

	cout << m3 << endl << m4 << endl;
}
