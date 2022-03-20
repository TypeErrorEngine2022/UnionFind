#pragma once
#include "Percolaton.h"

class PercolationStat{
private:
    double thresholdSum;
    std::size_t size;
    std::size_t trials;

public:
    //perform independent trials on a n-by-n grid
    PercolationStat(std::size_t sz, std::size_t times);
    
    //sample mean of percolation threshold
    double PercolationMean();
    
};