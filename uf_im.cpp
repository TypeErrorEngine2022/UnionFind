#include "Quickfind.h"

UF::UF(int n){
    id.reserve(n);
    count_ = n;
    for (int i = 0; i < n; i++){
        id.push_back(i);
    }
}

int UF::QFcount(){
    return count_;
}

bool UF::QFconnected(int p, int q){
    return id[p] == id[q];
}

int UF::find(int p){
    return id[p];
}

void UF::QFunion(int p, int q){
    /*
    O(n):
    At least = N + 3 array access, pid and qid -> 2, id[i] in loop -> N, the change for the only pid, id[i] = qid -> 1
    At most = 2N + 1 array access, pid and qid -> 2, id[i] in loop -> N, the change for (n-1) pid -> N - 1
    */    

    int pid = this->find(p);
    int qid = this->find(q);

    if (pid == qid) return;

    for (int i = 0; i < id.size(); i++){
        if (id[i] == pid) id[i] = qid; //rename all p-component into q;
    }
    --count_;
}
