#include "Percolaton.h"
#include "WeightedQuickUnionUF.h"
#include "gen_uf.h"

#include <vector>
#include <iostream>

Percolation::Percolation(int n): 
    WeightedQuickUnionUF(n * n)
{
    sz_grid = n;
    numberOfOpenSites_ = 0;
    grid.reserve(n * n);
    for (int i = 0; i < n * n; i++){ //n^2 complexity
        grid.push_back(closed); //initially all sites are closed
    }

    top = n * n; //top virtual site
    bottom = n * n + 1; //bottom virtual site

    int bot_tmp_ix = n * (n - 1) + 1 - 1; //bottom edge starts from [n][1]
    std::cout << "Construting...count is " << this->count() << std::endl;
    std::cout << this->percolates() << std::endl;
    
    for (int i = 0; i < n; i++){
        std::cout << "first connect" << std::endl;
        this -> WeightedUnion(i, top); //connect top edge and top
        this -> WeightedUnion(bot_tmp_ix, bottom); //connect bottom edge and bottom
        bot_tmp_ix++;
    }
    std::cout << this->percolates() << std::endl;
} 

void Percolation::open(int row, int col){
    //row:2 col:1 for size:5 = 5th element 
    // = size(row - 1) + col - 1 = 5(2-1) + 1 - 1
    int ix = sz_grid * (row - 1) + col - 1;
    if (grid[ix] != m_open) grid[ix] = m_open;
    ++numberOfOpenSites_;

    //connect to up, left, right, down sites if they are opened
    int up_ix = sz_grid * ((row - 1) - 1) + col - 1; 
    if (grid[up_ix] == m_open) this -> WeightedUnion(ix, up_ix);

    int left_ix = sz_grid * (row - 1) + (col - 1) - 1;
    if (grid[left_ix] == m_open) this -> WeightedUnion(ix, left_ix);

    int right_ix = sz_grid * (row - 1) + (col + 1) - 1;
    if (grid[right_ix] == m_open) this -> WeightedUnion(ix, right_ix);

    int down_ix = sz_grid * ((row + 1) - 1) + col - 1;
    if (grid[down_ix] == m_open) this -> WeightedUnion(ix, down_ix);
}

bool Percolation::isOpen(int row, int col)const{
    int ix = sz_grid * (row - 1) + col - 1;
    return (grid[ix] == m_open)? true:false;
}

bool Percolation::isFull(int row, int col){
    int ix = sz_grid * (row - 1) + col - 1;
    return connected(ix, top);
}

int Percolation::numberOfOpenSites()const{
    return numberOfOpenSites_;
}

bool Percolation::percolates(){
    std::cout << "top is " << top << std::endl;
    return this->connected(top, bottom);
}

void Percolation::testPercolateThreshold(){
    std::cout << "enter function\n";
    std::cout << "count is " << this->count() << std::endl;
    while (!(this->percolates())){
        int row = rand_uf(0, sz_grid - 1);
        int col = rand_uf(0, sz_grid - 1); 
        std::cout << "enter loop\n";
        if (!(this -> isOpen(row, col))){
            std::cout << "added 1\n";
            this -> open(row, col);
        }
    }
    std::cout << numberOfOpenSites_ << std::endl;
}
