#ifndef CHROMOSONE_H
#define CHROMOSONE_H

#include "board.h"
#include <vector>
class chromosone{
    public:
        chromosone(Board board_in) : board(board_in) {}
        int calculateFitness() const;
        void Mutate();
        void crossover(chromosone& other);
    private:
        Board board;
}

#endif