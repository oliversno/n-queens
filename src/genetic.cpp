#include "include/chromosone.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>
#include "matplotlib-cpp/matplotlibcpp.h"
using namespace std;
namespace plt = matplotlibcpp;

void genetic_algorithm(vector<chromosone>& chromosones){
    const int k = chromosones.size();
    vector<double> fitness;
    fitness.resize(k);
    transform(chromosones.begin(), chromosones.end(), fitness.begin(), 
        [](chromosone& c){ return c.get_fitness(); } );
    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<int> distrib(fitness.begin(), fitness.end()); // lookinto this
    // could be why fitness goes down
    vector<chromosone> temp = chromosones;
    for(int i = 0; i < k; ++i){
        int num = distrib(gen);
        temp[i] = chromosones[num];
    }
    chromosones = temp;
    for(int i = 0; i < k-1; i += 2){
        chromosones[i].crossover(chromosones[i+1]);
    }
    for(int i = 0; i < k; ++i){
        chromosones[i].mutate(10);
    }
    // update fitness
    for_each(chromosones.begin(), chromosones.end(), [](chromosone& c){
        c.calculateFitness(); 
    });
}


int main(int argc, char** argv){
    if(argc != 4){
        cerr << "Incorrect number of arguments: ./genetic SIZE_OF_BOARD POPULATION_SIZE" <<
            " NUMBER_OF_ROUNDS\n";
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int num_rounds = atoi(argv[3]);
    const int K_MutationRate = 50; // 0.05
    const int K_CrossoverRate = 70; // 0.7
    vector<chromosone> chromosones(k, chromosone( Board(n), K_MutationRate, K_CrossoverRate ));
    for_each(chromosones.begin(), chromosones.end(), [](chromosone& c){
        c.calculateFitness(); 
    });
    vector<double> total_fitness;
    total_fitness.reserve(num_rounds);
    for(int i = 0; i <= num_rounds; ++i){
        cout << "Round " << i << '\n';
        vector<double> fitness;
        fitness.reserve(k);
        for(int j = 1; j <= k; ++j){
            cout << "Chromosone " << j << '\n';
            cout << "-------------------\n";
            cout << chromosones[j-1] << '\n';
            if(chromosones[j-1].get_fitness() == 1.0){
                cout << "Solution Found" << '\n';
                return 0;
            }
            fitness.push_back(chromosones[j-1].get_fitness());
        }
        total_fitness.push_back(*max_element(fitness.begin(), fitness.end()));
        genetic_algorithm(chromosones);
    }
    plt::plot(total_fitness);
    plt::show();
}