#include "board_util.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>


static std::vector<std::vector<int>> board;

using namespace std;

void init_board() {
    board = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };
}

const std::vector<std::vector<int>>& get_board() {
    return board;
}

//Implement your code

// struct       
int count_full_lines() {
    return count_if(board.begin(), board.end(), [](const auto& row) {
        return all_of(row.begin(), row.end(), [](int elem) {
            return elem == 1;
        });
    });
}

void remove_full_lines(){
    auto to_remove = remove_if(board.begin(),board.end(),[](auto& i){
        return all_of(i.begin(),i.end(),[](auto elem){
            return elem == 1;
        });
    });
    int cnt = distance(to_remove, board.end());
    board.erase(to_remove,board.end());

    vector<vector<int>> new_lines(cnt, vector<int>(board[0].size(), 0));
    board.insert(board.begin(),new_lines.begin(),new_lines.end());
    return;
}

vector<int> get_heights() {
    const auto& board = get_board();
    int height = board.size();
    vector<int> bin(board[0].size(), 0);
    int col = 0;
    transform(bin.begin(), bin.end(), bin.begin(), [&](int) mutable {
        auto it = find_if(board.begin(), board.end(), [&](const auto& row){
            return row[col] == 1;
        });
        int result = (it != board.end()) * (height - distance(board.begin(), it));
        ++col;
        return result;
    });
    return bin;
}

int count_empty() {
    return accumulate(
        board.begin(), board.end(), 0,
        [](int total, const auto& row) {
            return total + count(row.begin(), row.end(), 0);
        }
    );
}