#include<bits/stdc++.h>
int C[20];
 
using namespace std;
 
void lecarta(int &x){
    C[x]++;
    if(x>10){
        x=10;
    }
}
 
int main(){
 
    int n=13;
    int M1, M2, J1, J2;
    int soma=0;
    int t;
 
    for(int i=1; i<=n; i++) C[i]=0;
 
    scanf("%d", &t);
 
    scanf("%d", &J1);
    lecarta(J1);
    scanf("%d", &J2);
    lecarta(J2);
    scanf("%d", &M1);
    lecarta(M1);
    scanf("%d", &M2);
    lecarta(M2);
 
    for(int i=0; i<t;i++){
        int temp;
        scanf("%d", &temp);
        lecarta(temp);
        soma+=temp;
    }
    int somam = soma+M1+M2;
    int somaj = soma+J1+J2;

    int diffm = 23 - somam;
    int diffj = 23 - somaj;

    if(diffm<=diffj){
        if(C[diffm]==4){
            cout << -1 << endl;
        }
        else{
            cout << diffm << endl;
        }
    }
    else{
        while(C[diffj]==4||somaj+diffj==23) diffj++;
        if(somam+diffj<=23 && somaj+diffj>=23){
            cout << diffj << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}