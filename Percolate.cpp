#include "Percolaton.h"
#include "WeightedQuickUnionUF.h"
#include "gen_uf.h"


Percolation::Percolation(int n): 
    weightedQU(n*n + 2)
{
    sz_grid = n;
    m_numberOfOpenSites = 0;
    grid.reserve(n * n);
    for (std::size_t i = 0; i < n * n; i++){ //n^2 complexity
        grid.push_back(closed); //initially all sites are closed
    }

    top = n * n; //top virtual site
    bottom = n * n + 1; //bottom virtual site

    std::size_t bot_tmp_ix = n * (n - 1) + 0; //bottom edge starts from [n - 1][0]
    
    for (std::size_t i = 0; i < n; i++){
        weightedQU.WeightedUnion(i, top); //connect top edge and top
        weightedQU.WeightedUnion(bot_tmp_ix, bottom); //connect bottom edge and bottom
        bot_tmp_ix++;
    }
} 

void Percolation::open(int row, int col){
    //row:1 col:0 for size 5 = grid[5]
    // = size(row) + col = 5(1) + 0
    if (isOpen(row, col)) return;
    
    std::size_t ix = sz_grid * row + col;
    grid[ix] = m_open;
    ++m_numberOfOpenSites;

    //connect to up, left, right, down sites if they are opened
    if ((row - 1) >= 0){ //up
        if(isOpen(row - 1, col)){
            std::size_t up_ix = sz_grid * (row - 1) + col;
            weightedQU.WeightedUnion(ix, up_ix);
        }
    }

    if ((col - 1) >= 0){ //left
        if(isOpen(row, col - 1)){
            std::size_t left_ix = sz_grid * row + (col - 1);
            weightedQU.WeightedUnion(ix, left_ix);
        }
    }

    if ((col + 1) <= sz_grid - 1){ //right
        if(isOpen(row, col + 1)){
            std::size_t right_ix = sz_grid * row + (col + 1);
            weightedQU.WeightedUnion(ix, right_ix);
        }
    }

    if ((row + 1) <= sz_grid - 1){ //down
        if(isOpen(row + 1, col)){
            std::size_t down_ix = sz_grid * (row + 1) + col;
            weightedQU.WeightedUnion(ix, down_ix);
        }
    }
}

bool Percolation::isOpen(int row, int col)const{
    std::size_t ix = sz_grid * row + col;
    return grid[ix];
}

bool Percolation::isFull(int row, int col){
    std::size_t ix = sz_grid * row + col;
    return weightedQU.connected(ix, top);
}

int Percolation::numberOfOpenSites()const{
    return m_numberOfOpenSites;
}

bool Percolation::percolates(){
    return weightedQU.connected(top, bottom);
}

double Percolation::testPercolateThreshold(){
    while (!percolates()){
        std::size_t row = rand_uf(0, sz_grid - 1);
        std::size_t col = rand_uf(0, sz_grid - 1); 
        open(row, col);
    }
    double threshold =  numberOfOpenSites() / static_cast<double>(sz_grid * sz_grid);
    return threshold;
}
