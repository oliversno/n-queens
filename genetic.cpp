#include "chromosone.h"
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

void genetic_algorithm(vector<chromosone>& chromosones){
    const int k = chromosones.size();
    vector<int> fitness;
    fitness.reserve(k);
    transform(chromosones.begin(), chromosones.end(), fitness.begin(), 
        [](const chromosone& c){ return c.calculateFitness(); } );
    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<int> distrib(fitness.begin(), fitness.end());
    vector<chromosone> temp;
    temp.reserve(k);
    for(int i = 0; i < k; ++i){
        int num = distrib(gen);
        temp[i] = chromosones[num];
    }
    chromosones = temp;
    for(int i = 0; i < k-1; i += 2){
        chromosones[i].crossover(chromosones[i+1]);
    }
    for(int i = 0; i < k; ++i){
        chromosones[i].Mutate();
    }
}


int main(int argc, char** argv){
    if(argc != 4){
        cerr << "Incorrect number of arguments: ./genetic SIZE_OF_BOARD POPULATION_SIZE" <<
            "NUMBER_OF_ROUNDS\n";
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int num_rounds = atoi(argv[3]);
    vector<chromosone> chromosones(k, chromosone( board(n) ));
    for_each(chromosones.begin(), chromosones.end(), [](chromosone& c){
        c.calculateFitness(); 
    });
    for(int i = 0; i < num_rounds; ++i){
        cout << "Round " << i << '\n';
        genetic_algorithm(chromosones);
        for(int j = 1; j <= k; ++j){
            cout << "Chromosone " << j << '\n';
            cout << "-------------------\n";
            cout << chromosones[j] << '\n';
        }
    }
}