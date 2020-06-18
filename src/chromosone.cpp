#include "include/chromosone.h"
#include <random>
#include <algorithm>

Board::Board(int n){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, n);
    auto generator = [&distrib, &gen](){
        return distrib(gen);
    };
    grid.resize(n);
    std::generate(grid.begin(), grid.end(), generator);
}

int Board::get_n() const{
    return grid.size();
}

int Board::at(int column_num) const{
    if(column_num < 0 || column_num >= grid.size()){
        throw outOfBoundsException();
    }
    return grid[column_num];
}

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