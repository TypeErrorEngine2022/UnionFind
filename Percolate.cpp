#include "Percolaton.h"
#include "WeightedQuickUnionUF.h"
#include <vector>

Percolation::Percolation(int n){
    sz_grid = n;
    numberOfOpenSites_ = 0;
    grid.reserve(n * n);
    for (int i = 0; i < n * n; i++){ //n^2 complexity
        grid.push_back(closed); //initially all sites are closed
    }

    WeightedQuickUnionUF uf(n * n + 2); 
    const int top = n * n; //top virtual site for
    const int bottom = n * n + 1; //bottom virtual site
    int bot_tmp_ix = n * (n - 1) + 1 - 1; //bottom edge starts from [n][1]
    for (int i = 0; i < n; i++){
        uf.WeightedUnion(i, top); //connect top edge and top
        uf.WeightedUnion(bot_tmp_ix, bottom); //connect bottom edge and bottom
        bot_tmp_ix++;
    }
} 

void Percolation::open(int row, int col){
    //row:2 col:1 for size:5 = 5th element 
    // = size(row - 1) + col - 1 = 5(2-1) + 1 - 1
    int ix = sz_grid * (row - 1) + col - 1;
    if (grid[ix] != open) grid[ix] = open;
    ++numberOfOpenSites_;

    //connect to up, left, right, down sites if they are opened
    int up_ix = sz_grid * ((row - 1) - 1) + col - 1; 
    if (grid[up_ix] == open) uf.WeightedUnion(ix, up_ix);

    int left_ix = sz_grid * (row - 1) + (col - 1) - 1;
    if (grid[left_ix] == open) uf.WeightedUnion(ix, left_ix);

    int right_ix = sz_grid * (row - 1) + (col + 1) - 1;
    if (grid[left_ix] == open) uf.WeightedUnion(ix, right_ix);

    int down_ix = sz_grid * ((row + 1) - 1) + col - 1;
    if (grid[left_ix] == open) uf.WeightedUnion(ix, down_ix);
}

bool Percolation::isOpen(int row, int col)const{
    int ix = sz_grid * (row - 1) + col - 1;
    return (grid[ix] == open)? true:false;
}

bool Percolation::isFull(int row, int col)const{
    int ix = sz_grid * (row - 1) + col - 1;
    return uf.connected(ix, top);
}

int Percolation::numberOfOpenSites()const{
    return numberOfOpenSites_;
}

bool Percolation::percolates()const{
    return uf.connected(top, bottom);
}

void Percolation::testPercolateThreshold(){
    while (!this->percolates()){
        
    }
}
