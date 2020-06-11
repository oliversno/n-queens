#ifndef BOARD_H
#define BOARD_H
#include<vector>
#include <iostream>

class Board{
    public:
        Board(std::vector<int> grid_in) : grid(grid_in) {}
        Board(int n);
        int get_n() const;
        int at(int column_num) const;

        friend std::ostream &operator<<( std::ostream &output, const board &B ){
            const int n = B.get_n();
            for(int column_num : B.grid){
                for(int i = 0; i < n; ++i){
                    if(i == column_num){
                        output << 'Q';
                    }
                    else{
                        output << '*';
                    }
                }
                output << '\n';
            }
            return output;
        }

    private:
        std::vector<int> grid;

};

#endif