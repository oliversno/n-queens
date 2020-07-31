#ifndef CHROMOSONE_H
#define CHROMOSONE_H
#include "include/board.h"
#include <vector>
#include <iostream>

class chromosone{
    public:
        chromosone(Board board_in) : board(board_in), fitness(-1) {}
        void calculateFitness();
        double get_fitness() const;
        void mutate(int mutation_prob);
        void crossover(chromosone& other);
        const Board get_board() const;

        static int nCk(int n, int k){
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

        friend std::ostream &operator<<( std::ostream &output, const chromosone &C ){
            output << C.get_board();
            output << "Fitness: " << C.fitness << '\n';
            return output;
        }
    private:
        Board board;
        double fitness;
};

//exceptions
struct notSameNExpception : public std::exception {
    const char* what() const throw(){
        return "Chromosones did not have same N for crossover";
    }
};

#endif