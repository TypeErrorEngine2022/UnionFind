#include "PercolationStat.h"
#include "Percolaton.h"

PercolationStat::PercolationStat(int sz, int times): size(sz), trials(times)
{
    thresholdSum = 0;
    for (int i = 0; i < times; i++){
        Percolation p(sz);
        thresholdSum += p.testPercolateThreshold();
    }
}

double PercolationStat::PercolationMean(){
    return thresholdSum / trials;
}