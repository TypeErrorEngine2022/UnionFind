#include "WeightedQuickUnionUF.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(int n){
    count_ = n;
    id.reserve(n);
    for (int i = 0; i < n; i++){
        id.push_back(i);
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
    while (p != id[p]){ //chase parent pointer until it reaches root => parent = parent's root => parent = root
        id[p] = id[id[p]]; //change root of p to its grandparent: path-compression
        p = id[p]; //go to parent
    }
    return p;
}

bool WeightedQuickUnionUF::connected(int p, int q){
    return this->root(p) == this->root(q);
}

void WeightedQuickUnionUF::WeightedUnion(int p, int q){
    int i = this->root(p);
    int j = this->root(q);

    if (i == j) return;
    if (sz[i] < sz[j]) {id[i] = j; sz[j] += sz[i]; }
    else {id[j] = i; sz[i] += sz[j]; }
    --count_;
}