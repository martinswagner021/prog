// ============================================================
// 
// Para a execucao deste codigo, foi utilizado o comando:
// $ gcc relatorio.c -o relatorio && ./relatorio >> saidarelatorio
// A fim de dar um append no documento anterior conforme o N era incrementado
// 
// A fim de resolver `o dumped core` tambem foi tentado utilizar somente um vetor
// por execucao, porem mesmo assim, a partir de 10^7 nem o quicksort foi possivel
//
// Creditos: Wagner Martins
//  
// ============================================================

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 10000000
#define lim 10000

void troca(int *v, int x, int y){
    int aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

void ordBolhaRec(int V[], int ini, int fim){
    if(fim>ini){
        for(int i=ini; i<fim;i++){
            if(V[i]>V[i+1]) troca(V, i, i+1);
        }
        ordBolhaRec(V, ini, fim-1);
    }
}

void ordBolha(int V[], int ini, int fim){
    for(int i=ini; i<fim;i++){
        for(int j=ini; j<fim;j++){
            if(V[j]>V[j+1]) troca(V, j, j+1);
        }
    }
}

void quicksort(int *v, int ini, int fim){
    if (ini < fim){
        int x = v[fim]; // fixa pivo
        int i = ini-1; // elementos menores
        int j = ini; // comparador
        // poe pivo no seu lugar correspondente e chama a funcao recursivamente
        while(j<fim){
            if(v[j]<=x){
                i++;
                troca(v, i, j);
            }
            j++;
        }
        i++;    
        troca(v, i, fim);
        quicksort(v, ini, i-1);
        quicksort(v, i+1, fim);
    }
}

void merge(int *v, int ini, int med, int fim){
	int* p, *q;
	int m = (med+1)-ini;
	int n = fim-med;
	// aloca vetores auxiliares e copia para dentro deles
	p = (int *) malloc((m)*sizeof(int));
	q = (int *) malloc(n*sizeof(int));
	for(int i=ini, j=0; i<=med; i++, j++) p[j] = v[i];
	for(int i=med+1, j=0; i<=fim; i++, j++) q[j] = v[i];

	// efetua o merge
	int i=0, j=0, k=ini;
	while(i<m && j<n){
		if(p[i]<q[j]) v[k++] = p[i++];
		else v[k++] = q[j++];
	}
	while(i<m) v[k++] = p[i++];
	while(j<n) v[k++] = q[j++];
}

void mergesort(int *v, int ini, int fim){
	if(fim>ini){
		int med = (ini+fim)/2;
		mergesort(v, ini, med);
		mergesort(v, med+1, fim);
		merge(v,ini,med,fim);
	}
}

// preenche aleatoriamente com tamanho: DEFINE N
void fillUpVecRand(int *V){
    srand(time(NULL));
    for(int i=0; i<N; i++) V[i]=rand()%lim;
}

int main(){

    int T[N];
    int U[N];
    int V[N];
    int W[N];

    fillUpVecRand(T);
    fillUpVecRand(U);
    fillUpVecRand(V);
    fillUpVecRand(W);

    // Output do relatorio ============================================================

    printf("==========================================\n");
    int constant = N;
    printf("N = %d\n", constant);

    // BolhaRecursivo
    float inicio = clock();
    ordBolhaRec(T, 0, N-1);
    float fim = clock();
    float tempo = (fim - inicio)/CLOCKS_PER_SEC;
    printf("Bolha Recursivo: %f\n", tempo);
    
    // BolhaIterativo
    inicio = clock();
    ordBolha(U, 0, N-1);
    fim = clock();
    tempo = (fim - inicio)/CLOCKS_PER_SEC;
    printf("Bolha Iterativo: %f\n", tempo);
    
    // Mergesort
    inicio = clock();
    mergesort(V, 0, N-1);
    fim = clock();
    tempo = (fim - inicio)/CLOCKS_PER_SEC;
    printf("Mergesort: %f\n", tempo);
    
    // Quicksort
    inicio = clock();
    quicksort(W, 0, N-1);
    fim = clock();
    tempo = (fim - inicio)/CLOCKS_PER_SEC;
    printf("Quicksort: %f\n", tempo);
     
}