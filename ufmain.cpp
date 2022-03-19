#include <iostream>
#include <fstream>
#include "Quickfind.h"
#include "WeightedQuickUnionUF.h"
#include "Percolaton.h"
#include "gen_uf.h"

using namespace std;

int main(){
    int size;
    cout << "Enter the size(N) of percolation grid(N-by-N):";
    cin >> size;

    /*ofstream uftxt("largeuf.txt");
    write_uf(uftxt, size);
    uftxt.close();*/

    /*ifstream infile("largeuf.txt");
    int tmp;*/
    /*if (infile.is_open()){    
        infile >> tmp; //just read the number for elements in txt
        int p, q;
        
        //Test for QFunion
        UF uf(size);
        while (infile >> p >> q){ 
            if (uf.QFconnected(p, q)) continue;
            uf.QFunion(p, q);
            //cout << p << " " << q << endl;
        }
        cout << uf.QFcount() << " components";

        //Test for WeightedQuickUnion
        WeightedQuickUnionUF wuf(size);
        while (infile >> p >> q){
            if (wuf.connected(p ,q)) continue;
            wuf.WeightedUnion(p, q);
            //cout << p << " " << q << endl; //io will slower the program!!
        }
        cout << wuf.count() << " components";
        infile.close();
    }*/

    Percolation pGrid(size);
    pGrid.testPercolateThreshold();

}

