#include "board.h"
#include <random>
#include <algorithm>

template <typename N>
board<N>::board(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, n);
    auto gen = [&distrib, &gen](){
        return distrib(gen);
    };
    std::generate(grid.begin(), grid.end(), gen);
}

template <typename N>
int board<N>::get_n() const{
    return N;
}

template <typename N>
int board<N>::at(int column_num) const{
    if(column_num < 0 || column_num >= grid.size()){
        throw outOfBoundsException();
    }
    return grid[column_num];
}

template <typename N>
std::vector<int> board<N>::get_grid() const{
    return grid;
}