#include "PercolationStat.h"
#include "Percolaton.h"

PercolationStat::PercolationStat(std::size_t sz, std::size_t times): size(sz), trials(times)
{
    thresholdSum = 0;
    for (std::size_t i = 0; i < times; i++){
        Percolation p(sz);
        thresholdSum += p.testPercolateThreshold();
    }
}

double PercolationStat::PercolationMean(){
    return thresholdSum / trials;
}