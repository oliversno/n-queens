#include "include/board.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

void min_conflict(Board& board, int max_steps){
    std::random_device rd;
    std::mt19937 gen(rd());
    const int n = board.get_n();
    std::uniform_int_distribution<> distrib(0, n-1);
    for(int i = 0; i < max_steps; i++){
        if(board.get_conflicts() == 0){ // solution found
            return;
        }
        int row = distrib(gen);
        vector<int> conflict_row = board.get_conflicts(row);
        int column = min_element(conflict_row.begin(), conflict_row.end()) - conflict_row.begin();
        board.set_queen(row, column);
    }
}

int main(int argv, char **argc){
    if(argv != 3){
        cerr << "Incorrect number of arguments: ./genetic SIZE_OF_BOARD MAX_STEPS\n";
    }
    int n = atoi(argc[1]);
    int max_steps = atoi(argc[2]);
    Board board{n};
    min_conflict(board, n);
    cout << "FINAL\n";
    cout << board;

}