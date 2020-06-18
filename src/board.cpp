#include "include/board.h"
#include <random>
#include <algorithm>
#include <limits>

Board::Board(int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, n);
    auto generator = [&distrib, &gen](){
        return distrib(gen);
    };
    grid.resize(n);
    std::generate(grid.begin(), grid.end(), generator);
}

int Board::get_n() const{
    if(grid.size() > std::numeric_limits<int>::max()){
        throw std::overflow_error("N is larger than INT_MAX");
    }
    return static_cast<int>(grid.size());
}

int Board::at(int column_num) const{
    if(column_num < 0 || column_num >= get_n() ){
        throw outOfBoundsException();
    }
    return grid[column_num];
}

void Board::swap(int pos1, int pos2){
    std::iter_swap(grid.begin()+pos1, grid.begin()+pos2);
}

void Board::swap(Board& other, int pos){
    std::iter_swap(grid.begin()+pos, other.grid.begin()+pos);
}
