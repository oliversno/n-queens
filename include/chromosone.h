#ifndef CHROMOSONE_H
#define CHROMOSONE_H
#include <vector>
#include <iostream>

class Board{
    public:
        Board(std::vector<int> grid_in) : grid(grid_in) {}
        Board(int n);
        int get_n() const;
        int at(int column_num) const;

        friend std::ostream &operator<<( std::ostream &output, const Board &B ){
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

class chromosone{
    public:
        chromosone(Board board_in) : board(board_in) {}
        int calculateFitness() const;
        void Mutate();
        void crossover(chromosone& other);
        const Board get_board() const;

        friend std::ostream &operator<<( std::ostream &output, const chromosone &C ){
            output << C.get_board();
        }
    private:
        Board board;
};

//helpers
int nCk(int n, int k){
    if(k==0){ return 1; }
    if(k > n / 2) { 
        return nCk(n, n-k);
    }
    long res = 1;
    for(int i = 1; i <= k; ++i){
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

//exceptions
struct outOfBoundsException : public std::exception {
    const char* what() const throw(){
        return "Column was not a valid acsess";
    }
};

#endif