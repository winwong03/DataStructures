//
//  quicksort.cpp
//  
//
//  Created by Winnie Wong on 2015-05-28.
//
//

#include "quicksort.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;
int comps;
int * x;

void swap( int & a, int & b ) {
    int tmp = a;
    a = b;
    b = tmp;
}

int randint( int a, int b ) {
    return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
    int i, m;
    comps++;
    if (a >= b) return;
    swap(x[a], x[randint(a,b)]);
    m = a;
    for (i = a+1; i <= b; i++) {
        comps++;
        if (x[i] < x[a])
            swap(x[++m], x[i]);
    }
    swap(x[a],x[m]);
    quicksort(a, m-1);
    quicksort(m+1, b);
}

int qc(int n) {
    
    if (n <= 1) {
        return 0;
    }
    
    else
    {
        int r = randint(0, n); //has to be down here because you want it be sure that r is not divisible by 0 and if you do the base case beforehand, you don't have to
        return ((n-1) + qc(r-1) + qc(n-r));
    }
}






int main( int argc, char *argv[] ) {
    srand(time(0));
    int p = 100;
    // change the following code
    
    while (p > 0) {
        
        x = new int[1000];
        
        for( int i=0; i<1000; ++i ) {
            x[i] = rand() % 1000;
        }
        
        quicksort(0, 999);
        
        for( int i=0; i<1000; ++i ) {
            cout << x[i] << " ";
        }
        cout << endl;
    
        delete[] x;
    
        p--;
        cout<< "the number of p is " << p << endl;
        
    }
    
    int j = qc(1000);
    
    cout << comps << endl;
    cout << comps/100 << endl;
    
    cout << "qc is " << j << endl;
    return 0;
}