#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 100000
#define lim 1000000

int V[N];

void troca(int *v, int x, int y){
    int aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

void ordBolha(int V[], int ini, int fim){
    if(fim>ini){
        for(int i=ini; i<fim-1;i++){
            if(V[i]<V[i+1]) troca(V, i, i+1);
        }
        ordBolha(V, ini, fim-1);
    }
}

void quicksort(int *v, int ini, int fim){
    if (ini < fim){
        int x = v[fim];
        int i = ini-1;
        int j = ini;
        while(j<fim){
            if(v[j]<=x){
                i=i+1;
                troca(v, i, j);
            }
            j=j+1;
        }
        i=i+1;
        troca(v, i, fim);
        quicksort(v, ini, i-1);
        quicksort(v, i+1, fim);
    }
}

int main() {

    srand(time(NULL));
    for(int i=0; i<N; i++){
        V[i]=rand()%lim;
    }

    float inicio = clock();
    quicksort(V, 0, N-1);
    float fim = clock();

    float tempo = (fim - inicio)/CLOCKS_PER_SEC;

    for(int i=0; i<100; i++) printf("%d ", V[i]);
    printf("\n");
    printf("%f\n", tempo);
}