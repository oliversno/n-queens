#include "genetic.h"
#include <cmath>
#include <random>
#include <time.h>
#include <algorithm>

void chromosone::calculateFitness(){
    fitness = 0;
    const int length = board.get_n();
    for(int i = 0; i < length; ++i){
        for(int j = i+1; i < length - 1; ++j){
            if(board.at(i) == board.at(j)){
                ++fitness;
            }
            else if (abs(board.at(i) - board.at(j)) == abs(i-j)){
                ++fitness;
            }
        }
    }
}
void chromosone::Mutate(){
    const int n = board.get_n();
    // seed rng
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, n);
    int randOne = distrib(gen);
    int randTwo = distrib(gen);
    while(randOne == randTwo){
        randTwo = distrib(gen); // ensure two distinct numbers
    }
    std::swap(board.at(randOne), board.at(randTwo));
    calculateFitness();
}
void chromosone::crossover(chromosone& other){
    if(board.get_n() != other.board.get_n()){
        throw notSameNError();
    }
    const int n = board.get_n();
    int slicePoint = n / 3;
    for(int i = 0; i < slicePoint; ++i){
        std::swap(board.at(i), other.board.at(i));
    }
    calculateFitness();
    other.calculateFitness();
}