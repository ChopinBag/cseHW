#include "Excel.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <sstream>


// Implement your code

using namespace std;

//public
Excel::Excel(const Table& data): data_(data){}

double Excel::average(int fromRow, int fromCol, int toRow, int toCol) const {
    if (!isValidRange(fromRow, fromCol, toRow, toCol)) return 0.0;
    fromRow--; fromCol--; toRow--; toCol--;
    auto cells = getCellsInRange(fromRow, fromCol, toRow, toCol);
    if (hasStringInRange(fromRow, fromCol, toRow, toCol)) return 0.0;
    if (cells.empty()) return 0.0;
    double sum = accumulate(cells.begin(), cells.end(), 0.0, [](double acc, const Cell& cell) {
        return acc + cell.getNumericValue();
    });
    return sum / cells.size();
}

string Excel::display() const{
    stringstream ss;
    for (const auto& row : data_){
        for (const auto& cell : row){
            ss << cell.toString() << "\t";
        }
        ss << '\n';
    }
    return ss.str();
}

//private
vector<Cell> Excel::getCellsInRange(int fromRow, int fromCol, int toRow, int toCol) const {
    vector<Cell> ret;
    if (fromRow > toRow) swap(fromRow, toRow);
    if (fromCol > toCol) swap(fromCol, toCol);
    for (int i = fromRow; i <= toRow; ++i) {
        for (int j = fromCol; j <= toCol; ++j) {
            ret.push_back(data_[i][j]);
        }
    }
    return ret;
}


bool Excel::hasStringInRange(int fromRow, int fromCol, int toRow, int toCol) const {
    auto cells = getCellsInRange(fromRow, fromCol, toRow, toCol);
    return any_of(cells.begin(), cells.end(), [](const Cell& cell) {
        return cell.isString();
    });
}


bool Excel::isValidRange(int fromRow, int fromCol, int toRow, int toCol) const{
    if (fromRow < 0 || fromCol < 0 || 
        toRow >= data_.size() || toCol >= data_[0].size()) {
        return false;
    }
    else return true;
}