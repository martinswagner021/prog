#include "bits/stdc++.h"

using namespace std;

int main(){
    int N = 100000;
    vector<int> x(N);
    for (int i=0; i<N; i++) x[i] = i;

    chrono::steady_clock sc;   // create an object of `steady_clock` class
    auto start = sc.now();     // start timer
    for (int i=0; i<N; i++){
        int max = 0;
        for (int j=i; j<N; j++){
            if (x[j] > x[max]) max = j;
        }
        int aux = x[i];
        x[i] = x[max];
        x[max] = aux;

    }
    auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
    auto time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "time taken: " << time_span.count() << endl;

}