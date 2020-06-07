#include "board.h"


int board::get_n() const{
    return grid.size();
}

std::vector<int> board::get_grid() const{
    return grid;
}