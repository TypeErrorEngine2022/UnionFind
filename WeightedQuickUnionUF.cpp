#include "WeightedQuickUnionUF.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(int n){
    count_ = n;
    parent.reserve(n);
    for (int i = 0; i < n; i++){
        parent.push_back(i);
    }
    sz.reserve(n);
    for (int i = 0; i < n; i++){
        sz.push_back(i);
    }  
}

int WeightedQuickUnionUF::count()const{
    return count_;
}

int WeightedQuickUnionUF::root(int p){
    while (p != parent[p]){ //chase parent pointer until it reaches root => parent = parent's root => parent = root
        parent[p] = parent[parent[p]]; //change root of p to its grandparent: path-compression
        p = parent[p]; //go to grandparent
    }
    return p;
}

bool WeightedQuickUnionUF::connected(int p, int q){
    return this->root(p) == this->root(q);
}

void WeightedQuickUnionUF::WeightedUnion(int p, int q){
    int rootP = this->root(p);
    int rootQ = this->root(q);

    if (rootP == rootQ) return;
    if (sz[rootP] < sz[rootQ]){
        parent[rootP] = rootQ;
        sz[rootQ] += sz[rootP]; 
    }
    else {
        parent[rootQ] = rootP; 
        sz[rootP] += sz[rootQ]; 
    }
    --count_;
}