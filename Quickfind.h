#pragma once

#include <vector>

class UF{
private:
    std::vector<int> id; //indexed by component
    int count_; //no of component
    int id_size; //no of element
    int find(int p); //find p's component
public:
    UF(int n);
    int count(); //return no of component
    bool connected(int p, int q); //check if their components' are equal
    void QFunion(int p, int q); //merge component
};
