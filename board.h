#ifndef BOARD_H
#define BOARD_H
#include<vector>
class board{
    public:
        board(std::vector<int> grid_in) : grid(grid_in) {}
        board(int n);
        int get_n() const;
        int at(int column_num) const;
    private:
        std::vector<int> grid;

};

#endif