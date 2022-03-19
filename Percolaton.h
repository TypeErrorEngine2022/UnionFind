#include <vector>

class Percolation{
private:
    // 0 -> open site, 1 -> closed site
    std::vector<std::vector<int>> grid; //outer:rows, inner: cols

public:
    Percolation(int n); //create n-by-n grid, with all sites initially closed
    void open(int row, int col); //open the site (row, col) if it is not open already
    bool isOpen(int row, int col); // is the site (row, col) open? 
    bool isFull(int row, int col); // is the site (row, col) Full?
    int numberOfOpenSites(); // return the number of open site
    bool percolates(); // does the system percolates?
}