#include "Quickfind.h"

UF::UF(int n){
    parent.reserve(n);
    count_ = n;
    for (int i = 0; i < n; i++){
        parent.push_back(i);
    }
}

int UF::QFcount(){
    return count_;
}

bool UF::QFconnected(int p, int q){
    return parent[p] == parent[q];
}

int UF::find(int p){
    return parent[p];
}

void UF::QFunion(int p, int q){
    /*
    O(n):
    At least = N + 3 array access, pid and qid -> 2, parent[i] in loop -> N, the change for the only pid, parent[i] = qid -> 1
    At most = 2N + 1 array access, pid and qid -> 2, parent[i] in loop -> N, the change for (n-1) pid -> N - 1
    */    

    int pid = this->find(p);
    int qid = this->find(q);

    if (pid == qid) return;

    for (int i = 0; i < parent.size(); i++){
        if (parent[i] == pid) parent[i] = qid; //rename all p-component into q;
    }
    --count_;
}
