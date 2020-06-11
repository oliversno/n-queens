#include "include/board.h"
#include <random>
#include <algorithm>

Board::Board(int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, n);
    auto gen = [&distrib, &gen](){
        return distrib(gen);
    };
    grid.resize(n);
    std::generate(grid.begin(), grid.end(), gen);
}

int Board::get_n() const{
    return grid.size();
}

int Board::at(int column_num) const{
    if(column_num < 0 || column_num >= grid.size()){
        throw outOfBoundsException();
    }
    return grid[column_num];
}