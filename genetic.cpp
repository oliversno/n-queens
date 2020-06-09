#include "chromosone.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    if(argc != 3){
        cerr << "Incorrect number of arguments: ./genetic N K\n";
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    vector<chromosone> chromosones(k, chromosone( board<n>() )); 
}