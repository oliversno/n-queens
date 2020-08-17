#include "include/board.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

bool is_safe(const Board& board, int row, int col){
    const int n = board.get_n();
    // left hand side
    for(int i = 0; i < n; ++i){
        if(board.at(i) == col || board.at(i) == abs(col-i)){
            return false;
        }
    }
    return true;
}

bool backtrack_util(Board board, int col){
    cout << "Trying col=" << col << '\n';
    cout << board;
    const int n = board.get_n();
    if(col >= n){
        return true;
    }
    for(int i = 0; i < n; ++i){
        if(is_safe(board, col, i)){
            board.set_queen(col, i);
            if(backtrack_util(board, col + 1)){
                return true;
            }
            board.remove_queen(i);
        }
    }
    return false; //queen can't be safely placed, backtrack
}

bool backtrack(Board& board){
    return backtrack_util(board, 0);
}

int main(int argv, char **argc){
    if(argv != 2){
        cerr << "Incorrect number of arguments: ./backtrack SIZE_OF_BOARD\n";
    }
    int n = atoi(argc[1]);
    Board board{n};
    board.clear();
    if(backtrack(board)){
        cout <<"Solution Found:\n";
        cout << board; 
    }
    else{
        cout << "No Solution Exists for N=" << n << '\n';
    }
}