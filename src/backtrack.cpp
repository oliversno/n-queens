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
        
    }
}

int main(int argv, char **argc){
    if(argv != 2){
        cerr << "Incorrect number of arguments: ./backtrack SIZE_OF_BOARD\n";
    }
    int n = atoi(argc[1]);
    Board board{n};

}