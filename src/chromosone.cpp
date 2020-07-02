#include "include/chromosone.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

void chromosone::calculateFitness(){
    const int n = board.get_n();
    fitness = chromosone::nCk(n, 2); //find number of pairs with nC2
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            try{
                if(board.at(i) == board.at(j)){
                    --fitness; //subtract for attacking pair
                }
                else if (abs(board.at(i) - board.at(j)) == abs(i-j)){
                    --fitness;
                }
            }
            catch(std::exception& e){
                std::cerr << "Exception caught in chromosone::calculateFitness() "
                    << e.what();
                exit(EXIT_FAILURE);
            }
        }
    }
}

int chromosone::get_fitness() const{
    return fitness;
}

void chromosone::mutate(int mutation_prob){
    const int n = board.get_n();
    // seed rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> probability_dist(0, 100);
    std::uniform_int_distribution<int> position_distrib(0, n-1);
    for(int i = 0; i < n; ++i){
        int rand_num = probability_dist(gen);
        if(mutation_prob <= rand_num){
            int new_pos = position_distrib(gen);
            
        }
    }

}
void chromosone::crossover(chromosone& other){
    if(board.get_n() != other.board.get_n()){
        throw notSameNExpception();
    }
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

const Board chromosone::get_board() const{
    return board;
}
