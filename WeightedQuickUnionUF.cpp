#include "WeightedQuickUnionUF.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(std::size_t n){
    m_count = n;
    nodes.reserve(n);
    for (std::size_t i = 0; i < n; i++){
        nodes.push_back({i, 0});
    }
}

std::size_t WeightedQuickUnionUF::count()const{
    return m_count;
}

std::size_t WeightedQuickUnionUF::root(std::size_t p){ 
    // Halving the path: makes every other node on the root path links to its grandparent
    // i.e. skip the parent, each jump by 2
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
    // Path Spliting: link every node on the root path to its grandparent
    while (p != nodes[p].parent){
        std::size_t nextP = nodes[p].parent;
        nodes[p].parent = nodes[nodes[p].parent].parent; // links to grandparent
        p = nextP;
    }
    return p;
}

bool WeightedQuickUnionUF::connected(std::size_t p, std::size_t q){
    return pathSplitRoot(p) == pathSplitRoot(q);
}

void WeightedQuickUnionUF::WeightedUnion(std::size_t p, std::size_t q){
    std::size_t rootP = pathSplitRoot(p);
    std::size_t rootQ = pathSplitRoot(q);

    if (rootP == rootQ) return;

    //Compare by number of element
    /*if (nodes[rootP].size < nodes[rootQ].size){
        nodes[rootP].parent = nodes[rootQ].parent;
        nodes[rootQ].size += nodes[rootP].size; 
    }
    else {
        nodes[rootQ].parent = nodes[rootP].parent; 
        nodes[rootP].size += nodes[rootQ].size; 
    }*/

    //Compare by height of the tree / rank
    if (nodes[rootP].size < nodes[rootQ].size){ 
        nodes[rootP].parent = nodes[rootQ].parent;
        nodes[rootP].size = nodes[rootQ].size; //smaller tree's height is replaced by higher tree's
    }
    else if (nodes[rootP].size > nodes[rootQ].size){
        nodes[rootQ].parent = nodes[rootP].parent; 
        nodes[rootQ].size = nodes[rootP].size; 
    }
    else {
        nodes[rootQ].parent = nodes[rootP].parent;
        nodes[rootP].size++; // when same height, link one to another increase the height of latter by one
        nodes[rootQ].size = nodes[rootP].size;
    }

    --m_count;
}