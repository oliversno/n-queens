#include "include/chromosone.h"
#include <random>
#include <algorithm>

int chromosone::calculateFitness() const{
    const int n = board.get_n();
    int fitness = nCk(n, 2); //find number of pairs with nC2
    const int length = board.get_n();
    for(int i = 0; i < length; ++i){
        for(int j = i+1; i < length - 1; ++j){
            if(board.at(i) == board.at(j)){
                --fitness; //subtract for attacking pair
            }
            else if (abs(board.at(i) - board.at(j)) == abs(i-j)){
                --fitness;
            }
        }
    }
    return fitness;
}
void chromosone::Mutate(){
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
    board.swap(randOne, randTwo);
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
        board.swap(other.board, i);
    }
}

const Board chromosone::get_board() const{
    return board;
}