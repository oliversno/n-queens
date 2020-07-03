#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>

class Board{
    public:
        Board(std::vector<int> grid_in) : grid(grid_in) {}
        Board(int n);
        int get_n() const;
        int at(int row_num) const;
        void set_queen(int row_num, int column_num);
        void swap(int pos1, int pos2);
        void swap(Board& other, int pos);

        bool operator==(const Board& other) const;
        bool operator!=(const Board& other) const;

        friend std::ostream &operator<<( std::ostream &output, const Board &B ){
            const int n = B.get_n();
            for(int row_num : B.grid){
                for(int i = 0; i < n; ++i){
                    if(i == row_num){
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

// exceptions
struct outOfBoundsException : public std::exception{
    private:
        const char* file;
        int line;
        const char* func;
        const char* info;
    public:
        outOfBoundsException(const char* file_, int line_, const char* func_, const char* info_ = "") :
        	file (file_),
        	line (line_),
        	func (func_),
        	info (info_)
            {
            }
        
        const char* what() const noexcept {
            static char res[100];
            sprintf(res, "Out of Bounds Exception in %s:%i function %s. Info: acsess at index %s", file, line, func, info);
            return res;
        }
};

#endif