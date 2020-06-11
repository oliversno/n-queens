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
        const Board get_board() const;

        friend std::ostream &operator<<( std::ostream &output, const chromosone &C ){
            output << C.get_board();
        }
    private:
        Board board;
}

#endif