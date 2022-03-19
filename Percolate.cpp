#include "Percolaton.h"
#include <vector>

Percolation::Percolation(int n){
    sz_grid = n;
    grid.reserve(n * n); //reserve n rows
    for (int i = 0; i < n * n; i++){
        grid.push_back(open);
    }
} 

void Percolation::open(int row, int col){
    //row:2 col:1 for size:5 = 5th element 
    // = size(row - 1) + col - 1 = 5(2-1) + 1 - 1
    int ix = sz_grid * (row - 1) + col - 1;
    if (grid[ix] != open) grid[ix] = open;
}

bool Percolation::isOpen(int row, int col){
    int ix = sz_grid * (row - 1) + col - 1;
    return (grid[ix] == open)? true:false;
}

bool Percolation::isFull(int row, int col){
    
}