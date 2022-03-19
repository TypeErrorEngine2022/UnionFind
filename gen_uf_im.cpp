#include "gen_uf.h"
#include <random>
#include <iostream>

int rand_uf(int range_from, int range_to){
    static std::random_device r1; //static: ensure only one seed in runtime
    static std::default_random_engine reng(r1()); //seed the random engine
    std::uniform_int_distribution<> distr(range_from, range_to); //initialize the range for the distribution
    return distr(reng); //transform the random unsigned int generated by reng into an int
}

void write_uf(std::ofstream& f1, int total){
    if (f1.is_open()){
        int range_from = 1;
        int range_to = total;
        f1 << total << std::endl; //indicate the number of elements in the union
        for (int i = 0; i < total; i++){
            f1 << rand_uf(range_from, range_to) << " " << rand_uf(range_from, range_to) << std::endl; //write a pair of element to be united
        }
    }
}