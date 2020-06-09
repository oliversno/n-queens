#ifndef GENETIC_H
#define GENETIC_H

#include "board.h"
#include <vector>

class chromosone{
    public:
        chromosone(Board board_in) : board(board_in) {}

        void calculateFitness();
        void Mutate();
        void crossover(chromosone& other);
    private:
        Board board;
        int fitness; // number of non attacking pairs
}

#endif