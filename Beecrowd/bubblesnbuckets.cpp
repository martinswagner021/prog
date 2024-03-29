#include<bits/stdc++.h>

using namespace std;

int n, v[100005], player=0; // player%2 determina marcelo ou carlos, marcelo = player%2

void troca(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

void sortbubble(){
    for(int j=0; j<n; j++){
        for(int i=0; i<n-1; i++){
            if(v[i+1]<v[i]){
                troca(&v[i],&v[i+1]);
                player++;
            }
        }
    }
}

void printV(){
    for(int i=0; i<n; i++) cout << "[" << v[i] << "]" << " ";
    cout << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // Um movimento de um jogador consiste na escolha de um par de elementos consecutivos da seqüência 
    // que estejam fora de ordem e em inverter a ordem dos dois elementos. Por exemplo, dada a seqüência
    //  1, 5, 3, 4, 2, o jogador pode inverter as posições de 5 e 3 ou de 4 e 2, mas não pode inverter as
    //  posições de 3 e 4, nem de 5 e 2

    
    cin >> n;

    while(n!=0){
        for (int i=0; i<n; i++){
            cin >> v[i];
        }

        // printV();
        sortbubble();
        // printV();
        // cout << endl;

        if(player%2 == 0){
            cout << "Carlos" << endl;
        }
        else{
            cout << "Marcelo" << endl;
        }
        
        player = 0;
        cin >> n;
    }

}