#include <vector>

class Percolation{
private:
    // 0 -> open site, 1 -> closed site
    std::vector<int> grid; //n^2 site
    const int sz_grid; //size of grid, 5-by-5 grid has size 5
    const int open = 1;
    const int closed = 0;

public:
    Percolation(int n); //create n-by-n grid, with all sites initially closed
    void open(int row, int col); //open the site (row, col) if it is not open already
    bool isOpen(int row, int col); // is the site (row, col) open? 
    bool isFull(int row, int col); // is the site (row, col) Full?
    int numberOfOpenSites(); // return the number of open site
    bool percolates(); // does the system percolates?
}