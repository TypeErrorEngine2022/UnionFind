#pragma once
#include <random>
#include <fstream>

int rand_uf(int range_from, int range_to); //gen random number for the uf elements

void write_uf(std::ofstream& f1, int total); //write random uf elements into file
