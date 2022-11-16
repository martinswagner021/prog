#include<bits/stdc++.h>

using namespace std;

void printM(int **m, int lin, int col){
    cout << endl;
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

typedef struct pedido{
    int tempo;
    int qtd;
} Pedido;

bool comp(Pedido a, Pedido b){
    return a.qtd < b.qtd;
}

int binmochila(int lin, int col, vector <Pedido> pedidos){
    lin++;
    col++;
    // cria matriz da mochila
    int **m = (int**) malloc(lin*sizeof(int*));
    for(int i=0; i<lin; i++){
        m[i] = (int*) malloc(col*sizeof(int));
    }

    // preenche mochila com 0 nos primeiros arrays
    for(int i=0; i<lin; i++) m[i][0] = 0;
    for(int i=0; i<col; i++) m[0][i] = 0;

    for(int i=1; i<lin; i++){
        for(int j=1; j<col; j++){
            if(j-pedidos[i-1].qtd<0){
                m[i][j] = m[i-1][j];
            }
            else{
                m[i][j] = max(m[i-1][j],m[i-1][j-pedidos[i-1].qtd]+pedidos[i-1].tempo);
            }
        }
    }

    int x = m[lin-1][col-1];

    return x;
}


int main() {
    int n, p; //n: leituras, p: pedidos
    vector <Pedido> pedidos;
    // input
    scanf("%d", &n);
    while(n!=0){
        scanf("%d",&p);
        for(int i=0; i<n; i++){
            Pedido temp;
            scanf("%d %d", &temp.tempo, &temp.qtd);
            pedidos.push_back(temp);
        }

        //solution
        cout << binmochila(n, p, pedidos) << " min." << endl;
    
        // reads n to looping
        pedidos.clear();
        scanf("%d", &n);
    }
}