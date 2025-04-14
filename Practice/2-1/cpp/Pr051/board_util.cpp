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
int count_full_lines(){
    count_if(board.begin(),board.end(),[](auto li){
        return all_of(li.begin(),li.end(), [](auto elem){
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

vector<int> get_heights(){
    vector<int> bin;
    int n1 = 0;
    int n2 = 0;
    for_each(board.begin(),board.end(),[](auto i){
        
        return for_each(i.begin(),i.end(),[](auto el){
            vector[n2] = el? n1++: vector[n2++];
        })
    })


    
}