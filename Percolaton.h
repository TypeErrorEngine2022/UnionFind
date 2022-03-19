#include <vector>
#include <iostream>

#include "WeightedQuickUnionUF.h"
#include "gen_uf.h"

class Percolation: private WeightedQuickUnionUF{
private:
     //n^2 site
    std::vector<int> grid;

    //size of grid, 5-by-5 grid has size 5
    int sz_grid; 

    const int m_open = 1;

    const int closed = 0;

    //top virtual site
    int top; 

    //bottom virtual site
    int bottom;

    int numberOfOpenSites_;

public:
    //create n-by-n grid, with all sites initially closed
    Percolation(int n); 

    //open the site (row, col) if it is not open already
    void open(int row, int col); 
    
    // is the site (row, col) open? 
    bool isOpen(int row, int col)const; 

    // is the site (row, col) Full?
    bool isFull(int row, int col); 

    // return the number of open site
    int numberOfOpenSites()const; 

    // does the system percolates?
    bool percolates(); 

    //Monte Carlo Simulation
    void testPercolateThreshold();
};