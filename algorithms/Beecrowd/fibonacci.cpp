#include<bits/stdc++.h>

using namespace std;


int calls(int n, int *chamadas){
    if(n==0) {
        (*chamadas)++;
        return 0;
    }
    if(n==1){
        (*chamadas)++;
        return 1;
    }
    
    (*chamadas)++;
    return calls(n-1, chamadas)+calls(n-2, chamadas);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int chamadas = -1;
        int x, temp;
        scanf("%d", &x);
        temp = calls(x, &chamadas);
        cout << "fib(" << x << ") = "<< chamadas << " calls = " << temp << endl;
        chamadas = -1;
    }
}