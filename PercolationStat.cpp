#include "PercolationStat.h"

#include <iostream>
#include <iomanip>

PercolationStat::PercolationStat(std::size_t sz, std::size_t times): size(sz), trials(times)
{
    thresholdSum = 0;
    for (std::size_t i = 0; i < times; i++){
        Percolation p(sz);
        double threshold = p.testPercolateThreshold();
        thresholds.push_back(threshold); //store the threshold at each time
        thresholdSum += threshold;
    }
}

double PercolationStat::thresholdMean(){
    return thresholdSum / trials;
}

double PercolationStat::thresholdStddev(){
    double errorSquareSum = 0;
    for (double threshold: thresholds){
        double errorSquare = pow( threshold - thresholdMean(), 2);
        errorSquareSum += errorSquare;
    }
    double stddev = errorSquareSum / (trials - 1);
    return stddev;
}

double PercolationStat::thresholdConfidenceLo(){
    return thresholdMean() - (1.96 * thresholdStddev()) / (sqrt(trials));
}

double PercolationStat::thresholdConfidenceHi(){
    return thresholdMean() + (1.96 * thresholdStddev()) / (sqrt(trials));
}

template<typename T>
void PercolationStat::printElement(T el, const int& width)
{
    const char separator = ' ';
    std::cout << std::left << std::setw(width) << std::setfill(separator) << el;
}

void PercolationStat::displayThresholdStat(){
    printElement("mean", 24);
    printElement("=", 2);
    std::cout.precision(std::numeric_limits<double>::digits10);
    std::cout << std::left << thresholdMean() << "\n";
    printElement("stddev", 24);
    printElement("=", 2);
    std::cout << std::left << thresholdStddev() << "\n";
    printElement("95% confidence level", 24);
    printElement("=", 2);
    std::cout << "[";
    std::cout << std::left << thresholdConfidenceLo();
    std::cout << ", ";
    std::cout << std::left << thresholdConfidenceHi();
    std::cout << "]\n";
}