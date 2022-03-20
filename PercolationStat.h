#pragma once
#include "Percolaton.h"

class PercolationStat{
private:
    double thresholdSum;
    int size;
    int trials;
public:
    //perform independent trials on a n-by-n grid
    PercolationStat(int sz, int times);
    
    //sample mean of percolation threshold
    double PercolationMean();
    
};