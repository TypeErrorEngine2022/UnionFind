#pragma once

#include <vector>

class WeightedQuickUnionUF{
private:
    std::vector<int> id; //parent link(site indexed)
    std::vector<int> sz; //size of component for roots(site indexed) / no of element in tree
    int count_; //number of components/tree
    
public:
    WeightedQuickUnionUF(int n);
    int count()const; //return no of component
    bool connected(int p, int q); //check if their components' are equal
    void WeightedUnion(int p, int q); //merge trees tgt, smaller tree becomes child of larger tree

private:
    int root(int p); //return root of p
};