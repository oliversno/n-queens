#include "include/board.h"
#include <random>
#include <algorithm>
#include <limits>
#include <string>

Board::Board(int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, n-1);
    auto generator = [&distrib, &gen](){
        return distrib(gen);
    };
    grid.resize(n);
    std::generate(grid.begin(), grid.end(), generator);
}

int Board::get_n() const{
    int n = static_cast<int>(grid.size());
    if(n > std::numeric_limits<int>::max()){
        throw std::overflow_error("N is larger than INT_MAX");
    }
    return n;
}

int Board::at(int row_num) const{
    if(row_num < 0 || row_num >= get_n() ){
        throw outOfBoundsException("board.cpp", 27, "at(int)", std::to_string(row_num).c_str());
    }
    return grid[row_num];
}

void Board::set_queen(int row_num, int column_num){
    grid[row_num] = column_num;
    if(row_num < 0 || row_num >= get_n() ){
        throw outOfBoundsException("board.cpp", 27, "set_queen(int, int)", std::to_string(row_num).c_str());
    }
}

void Board::swap(int pos1, int pos2){
    if(pos1 < 0 || pos1 >= get_n()){
        throw outOfBoundsException("board.cpp", 34, "swap(int, int)", std::to_string(pos1).c_str());
    }  
    if(pos2 < 0 || pos2 > get_n()){
        throw outOfBoundsException("board.cpp", 37, "swap(int, int)", std::to_string(pos2).c_str());
    }
    std::iter_swap(grid.begin()+pos1, grid.begin()+pos2);
}

void Board::swap(Board& other, int pos){
    if(pos < 0 || pos > get_n() || pos > other.get_n()){
        throw outOfBoundsException("board.cpp", 44, "swap(const Board&, int)", std::to_string(pos).c_str());
    }
    std::iter_swap(grid.begin()+pos, other.grid.begin()+pos);
}

bool Board::operator==(const Board& other) const{
    return grid == other.grid;
}
bool Board::operator!=(const Board& other) const{
    return !(*this == other);
}
