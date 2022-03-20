#include "Percolaton.h"
#include "WeightedQuickUnionUF.h"
#include "gen_uf.h"

#include <vector>
#include <iostream>

Percolation::Percolation(int n): 
    WeightedQuickUnionUF(n * n + 2)
{
    sz_grid = n;
    numberOfOpenSites_ = 0;
    grid.reserve(n * n);
    for (int i = 0; i < n * n; i++){ //n^2 complexity
        grid.push_back(closed); //initially all sites are closed
    }

    top = n * n; //top virtual site
    bottom = n * n + 1; //bottom virtual site

    int bot_tmp_ix = n * (n - 1) + 0; //bottom edge starts from [n - 1][0]
    
    for (int i = 0; i < n; i++){
        WeightedUnion(i, top); //connect top edge and top
        WeightedUnion(bot_tmp_ix, bottom); //connect bottom edge and bottom
        bot_tmp_ix++;
    }
} 

void Percolation::open(int row, int col){
    //row:1 col:0 for size 5 = grid[5]
    // = size(row) + col = 5(1) + 0
    int ix = sz_grid * row + col;
    if (!isOpen(row, col)) grid[ix] = m_open;
    ++numberOfOpenSites_;

    //connect to up, left, right, down sites if they are opened
    if ((row - 1) >= 0){ //up
        if(isOpen(row - 1, col)){
            int up_ix = sz_grid * (row - 1) + col;
            WeightedUnion(ix, up_ix);
        }
    }

    if ((col - 1) >= 0){ //left
        if(isOpen(row, col - 1)){
            int left_ix = sz_grid * row + (col - 1);
            WeightedUnion(ix, left_ix);
        }
    }

    if ((col + 1) <= sz_grid - 1){ //right
        if(isOpen(row, col + 1)){
            int right_ix = sz_grid * row + (col + 1);
            WeightedUnion(ix, right_ix);
        }
    }

    if ((row + 1) <= sz_grid - 1){ //down
        if(isOpen(row + 1, col)){
            int down_ix = sz_grid * (row + 1) + col;
            WeightedUnion(ix, down_ix);
        }
    }
}

bool Percolation::isOpen(int row, int col)const{
    int ix = sz_grid * row + col;
    if (grid[ix] == m_open) return true;
    else return false;
}

bool Percolation::isFull(int row, int col){
    int ix = sz_grid * row + col;
    return connected(ix, top);
}

int Percolation::numberOfOpenSites()const{
    return numberOfOpenSites_;
}

bool Percolation::percolates(){
    return connected(top, bottom);
}

double Percolation::testPercolateThreshold(){
    while (!percolates()){
        int row = rand_uf(0, sz_grid - 1);
        int col = rand_uf(0, sz_grid - 1); 
        if (!isOpen(row, col)){
            open(row, col);
        }
    }
    double threshold =  numberOfOpenSites() / static_cast<double>(sz_grid * sz_grid);
    return threshold;
}
