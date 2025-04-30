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

double Excel::average(int fromRow, int fromCol, int toRow, int toCol) const{
    fromRow--;fromCol--;toRow--;toCol--; // 1-based
    auto cells = getCellsInRange(fromRow,fromCol,toRow,toCol);
    if(hasStringInRange(fromRow,fromCol,toRow,toCol)) return 0.0;
    double sum = accumulate(cells.begin(),cells.end(),0.0,[](double acc, auto cell){
        return acc+cell.getNumericValue();
    });
    return sum / cells.size();
}

string Excel::display() const{
    stringstream ss;
    for(int i=0; i < 3;++i){
        for(int j= 0; j< 3; ++j){
            ss << data_[i][j].toString();
        }
        ss << '\n';
    }
    return ss.str();
}

//private
vector<Cell> Excel::getCellsInRange(int fromRow, int fromCol, int toRow, int toCol) const{
    vector<Cell> ret;
    for(int i=--fromRow; i < --toRow;++i){
        for(int j= --fromCol; j< --toCol; ++j){
            ret.push_back(data_[i][j]);
        }
    }
    return ret;
}

bool Excel::hasStringInRange(int fromRow, int fromCol, int toRow, int toCol) const{
    auto cells = getCellsInRange(fromRow,fromCol,toRow,toCol);
    return any_of(cells.begin(), cells.end(), [](auto cell){
        return cell.isString();
    })
}

bool Excel::isValidRange(int fromRow, int fromCol, int toRow, int toCol) const{
    if(fromRow < 1 || fromCol < 1 || --toRow > 3 || --toCol > 3) return false;
    else return true;
}