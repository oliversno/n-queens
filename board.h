#ifndef BOARD_H
#define BOARD_H
#include<vector>
class board{
    public:
        board(std::vector<int> grid_in) : grid(grid_in) {}
        
        int get_n() const;
        std::vector<int> get_grid() const;
    private:
        const std::vector<int> grid;

};

#endif