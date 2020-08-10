#include "include/chromosone.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

void chromosone::calculateFitness(){
    int num_threats = board.get_conflicts(); // max nC2
    fitness = 1.0/(1.0+num_threats);
}

double chromosone::get_fitness() const{
    return fitness;
}

void chromosone::mutate(int mutation_prob){
    int r = rand() % 1000;
    if(r < mutationRate){
        const int n = board.get_n();
        // seed rng
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> probability_distrib(0, 100);
        std::uniform_int_distribution<int> position_distrib(0, n-1);
        for(int i = 0; i < n; ++i){
            int rand_num = probability_distrib(gen);
            if(rand_num <= mutation_prob){
                int new_pos = position_distrib(gen);
                try{
                    board.set_queen(i, new_pos);
                }
                catch(std::exception& e){
                    std::cerr << "Exception caught in chromosone::mutate(int) "
                        << e.what();
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
}
void chromosone::crossover(chromosone& other){
    if(board.get_n() != other.board.get_n()){
        throw notSameNExpception();
    }
    int r = rand() % 100;
    if(r < crossoverRate){
        const int n = board.get_n();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, n);
        int slicePoint = distrib(gen);
        for(int i = 0; i < slicePoint; ++i){
            try{
                board.swap(other.board, i);
            }
            catch(std::exception& e){
                std::cerr << "Exception caught in chromosone::crosover(chromosone&) "
                    << e.what();
                exit(EXIT_FAILURE);
            }
        }
    }
}

const Board chromosone::get_board() const{
    return board;
}
