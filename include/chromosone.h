#ifndef CHROMOSONE_H
#define CHROMOSONE_H
#include "include/board.h"
#include <vector>
#include <iostream>

class chromosone{
    public:
        chromosone(Board board_in) : board(board_in) {}
        int calculateFitness() const;
        void Mutate();
        void crossover(chromosone& other);
        const Board get_board() const;

        friend std::ostream &operator<<( std::ostream &output, const chromosone &C ){
            output << C.get_board();
            return output;
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
    int res = 1;
    for(int i = 1; i <= k; ++i){
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

//exceptions
struct notSameNExpception : public std::exception {
    const char* what() const throw(){
        return "Chromosones did not have same N for crossover";
    }
};

#endif