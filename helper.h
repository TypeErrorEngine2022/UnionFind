#pragma once

#include "PercolationStat.h"
#include <random>
#include <fstream>
#include <random>
#include <iostream>
#include <chrono>
#include <iomanip>

int randNum(int range_from, int range_to); //gen random number for the uf elements

void write_uf(std::ofstream& f1, int total); //write random uf elements into file

std::chrono::duration<float> timeTrial(std::size_t size);

template<typename T> 
void printElement(T el, const int& width);

#include "print.tpp"