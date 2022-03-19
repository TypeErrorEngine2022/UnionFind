#include "Percolaton.h"
#include <vector>

Percolation::Percolation(int n){
    grid.reserve(n); //reserve n rows
    for (auto %cols: grid){
        &cols.reserve(n); 
        for (int site = 0; site < n; site++){
            &cols[site] = 0; //closed
        }
    }
}  