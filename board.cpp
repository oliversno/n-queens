#include "board.h"
#include <random>
#include <algorithm>

board::board(int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, n);
    auto gen = [&distrib, &gen](){
        return distrib(gen);
    };
    grid.resize(n);
    std::generate(grid.begin(), grid.end(), gen);
}

int board::get_n() const{
    return grid.size();
}

int board::at(int column_num) const{
    if(column_num < 0 || column_num >= grid.size()){
        throw outOfBoundsException();
    }
    return grid[column_num];
}