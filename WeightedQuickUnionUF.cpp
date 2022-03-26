#include "WeightedQuickUnionUF.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(std::size_t n){
    m_count = n;
    nodes.reserve(n);
    for (std::size_t i = 0; i < n; i++){
        nodes.push_back({i, 1});
    }
}

std::size_t WeightedQuickUnionUF::count()const{
    return m_count;
}

std::size_t WeightedQuickUnionUF::root(std::size_t p){ 
    while (p != nodes[p].parent){ //chase parent pointer until it reaches root => parent = parent's root => parent = root
        nodes[p].parent = nodes[nodes[p].parent].parent; //change root of p to its grandparent: halved the path
        p = nodes[p].parent; //go to grandparent
    }
    return p;
}

std::size_t WeightedQuickUnionUF::recursiveRoot(std::size_t p){
    if (p == nodes[p].parent) return p;  

    return recursiveRoot(nodes[nodes[p].parent].parent);
}

std::size_t WeightedQuickUnionUF::pathSplitRoot(std::size_t p){
    while (p != nodes[p].parent){
        std::size_t currentParent = nodes[p].parent;
        std::size_t grandParent = nodes[currentParent].parent;
        std::size_t grandGrandParent = nodes[grandParent].parent;
        nodes[currentParent].parent = grandGrandParent;
        currentParent = grandParent;
        p = currentParent;
    }
    
    return p;
}

bool WeightedQuickUnionUF::connected(std::size_t p, std::size_t q){
    return root(p) == root(q);
}

void WeightedQuickUnionUF::WeightedUnion(std::size_t p, std::size_t q){
    std::size_t rootP = root(p);
    std::size_t rootQ = root(q);

    if (rootP == rootQ) return;
    if (nodes[rootP].size < nodes[rootQ].size){
        nodes[rootP].parent = nodes[rootQ].parent;
        nodes[rootQ].size += nodes[rootP].size; 
    }
    else {
        nodes[rootQ].parent = nodes[rootP].parent; 
        nodes[rootP].size += nodes[rootQ].size; 
    }
    --m_count;
}