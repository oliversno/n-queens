#include "board.h"


int board::get_n() const{
    return grid.size();
}

int board::at(int column_num) const{
    if(column_num < 0 || column_num >= grid.size()){
        throw outOfBoundsException();
    }
    return grid[column_num];
}

std::vector<int> board::get_grid() const{
    return grid;
}