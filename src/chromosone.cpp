#include "include/chromosone.h"
#include <cmath>
#include <random>
#include <time.h>
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
    std::swap(board.at(randOne), board.at(randTwo));
}
void chromosone::crossover(chromosone& other){
    if(board.get_n() != other.board.get_n()){
        throw notSameNError();
    }
    const int n = board.get_n();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, n);
    int slicePoint = distrib(gen);
    for(int i = 0; i < slicePoint; ++i){
        std::swap(board.at(i), other.board.at(i));
    }
}

const Board chromosone::get_board() const{
    return board;
}

//helpers
int nCk(int n, int k){
    if(k==0){ return 1; }
    if(k > n / 2) { 
        return nCk(n, n-k);
    }
    long res = 1;
    for(int i = 1; i <= k; ++i){
        res *= n - i + 1;
        res /= i;
    }
    return res;
}