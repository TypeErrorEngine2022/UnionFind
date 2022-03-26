#pragma once

#include <vector>

class WeightedQuickUnionUF{
private:
    struct Node
    {
        std::size_t parent; //parent link(site indexed)
        std::size_t size; //size of component for roots(site indexed) / no of element in tree
    };

    std::vector<Node> nodes;

    std::size_t m_count; //number of components/tree
    
public:
    WeightedQuickUnionUF(std::size_t n);
    std::size_t count()const; //return no of component
    bool connected(std::size_t p, std::size_t q); //check if their components' are equal
    void WeightedUnion(std::size_t p, std::size_t q); //merge trees tgt, smaller tree becomes child of larger tree

private:
    std::size_t root(std::size_t p); //return root of p
    std::size_t recursiveRoot(std::size_t p);
};