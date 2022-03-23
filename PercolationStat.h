#pragma once
#include "Percolaton.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>

class PercolationStat{
private:
    double thresholdSum;
    std::vector<double> thresholds;
    std::size_t size;
    std::size_t trials;

public:
    //perform independent trials on a n-by-n grid
    PercolationStat(std::size_t sz, std::size_t  times);
    
    //sample mean of percolation threshold
    double thresholdMean();
    
    //sample standard deviation of percolation threshold
    double thresholdStddev();

    //low endpoint of 95% confidence interval
    double thresholdConfidenceLo();

    //high endpoint of 95% confidence interval
    double thresholdConfidenceHi();

    //print mean, stddev and confidence interval in format
    void displayThresholdStat();

private:
    template<typename T>
    void printElement(T el, const int& width);
};