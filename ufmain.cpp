#include <iostream>
#include <fstream>
#include "Quickfind.h"
#include "WeightedQuickUnionUF.h"
#include "Percolaton.h"
#include "helper.h"
#include "PercolationStat.h"

using namespace std;

int main(){
    /*int size;
    cout << "Enter the size(N) of percolation grid(N-by-N):";
    cin >> size;*/

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

    /*cout << "Enter number of time of simulation:";
    int time;
    cin >> time;
    PercolationStat pStat(size, time);
    pStat.displayThresholdStat();*/
    
    std::size_t size = 125;
    std::chrono::duration<float> prev_duration = timeTrial(size);
    for (std::size_t i = 0; i < 5 ; i++){
        size *= 2;
        std::chrono::duration<float> duration = timeTrial(size);
        printElement(size, 6);
        printElement(duration.count(), 6);
        printElement(duration / prev_duration, 6);
        prev_duration = duration;
    }

}

