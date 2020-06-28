#include "include/chromosone.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

int chromosone::calculateFitness() const{
    const int n = board.get_n();
    int fitness = chromosone::nCk(n, 2); //find number of pairs with nC2
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
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
    return fitness;
}
void chromosone::mutate(){
    const int n = board.get_n();
    // seed rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, n);
    int randOne = distrib(gen);
    int randTwo = distrib(gen);
    while(randOne == randTwo){
        randTwo = distrib(gen); // ensure two distinct numbers
    }
    try{
        board.swap(randOne, randTwo);
    }
    catch(std::exception& e){
            std::cerr << "Exception caught in chromosone::mutate() "
                << e.what();
            exit(EXIT_FAILURE);
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
