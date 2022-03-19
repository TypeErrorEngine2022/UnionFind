#include <iostream>
#include <fstream>
#include "Quickfind.h"
#include "WeightedQuickUnionUF.h"
#include "gen_uf.h"

using namespace std;

int main(){
    ofstream uftxt("largeuf.txt");
    int total;
    cout << "Enter the total number of elements:";
    cin >> total;
    write_uf(uftxt, total);
    uftxt.close();

    ifstream infile("largeuf.txt");
    int tmp;
    if (infile.is_open()){    
        infile >> tmp; //just read the number for elements in txt
        int p, q;
        
        //Test for QFunion
        /*UF uf(total);
        while (infile >> p >> q){ 
            if (uf.connected(p, q)) continue;
            uf.QFunion(p, q);
            //cout << p << " " << q << endl;
        }
        cout << uf.count() << " components";*/

        //Test for WeightedQuickUnion
        WeightedQuickUnionUF wuf(total);
        while (infile >> p >> q){
            if (wuf.connected(p ,q)) continue;
            wuf.WeightedUnion(p, q);
            //cout << p << " " << q << endl; //io will slower the program!!
        }
        cout << wuf.count() << " components";
        infile.close();
    }
}

