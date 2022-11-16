#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

#define N 1000000

using namespace std;

bool ordering_mode(int x, int y){
    return x > y;
}

void printvector(vector<int> v){
    for(int i: v){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){

    vector<int> A = {};

    for(int i=0; i<N; i++) A.push_back(i);

    sort(A.begin(), A.end());

    //printvector(A);

    auto i = upper_bound(begin(A), end(A), 12);
    
    if(i!=end(A)){
        A.insert(i, 5);
    }

    for(int &i: A){
        if(i%2==0){
            i*=2;
        }
    }
    
    // printvector(A);
}