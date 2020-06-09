#ifndef BOARD_H
#define BOARD_H
#include<vector>
template <int N>
class board{
    public:
        board(std::vector<int> grid_in) : grid(grid_in) {}
        board();
        int get_n() const;
        int at(int column_num) const;
        std::vector<int> get_grid() const;
    private:
        const std::vector<int> grid(N, -1);

};

#endif