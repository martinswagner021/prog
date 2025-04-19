#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define T 1000
#define lim 1000

void printvet(int* v, int n){
	printf("vetor: ");
	for(int i=0; i<n; i++) printf("%d ",v[i]);
	printf("\n");
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

	// area de teste
	// printvet(p, m);
	// printvet(q, n);
}

void mergesort(int *v, int ini, int fim){
	if(fim>ini){
		int med = (ini+fim)/2;
		mergesort(v, ini, med);
		mergesort(v, med+1, fim);
		merge(v,ini,med,fim);
	}
}

int main(){
	int N = 5;

	int* v = (int *) malloc(T*sizeof(int));

	srand(time(NULL));
	for(int i=0; i<T; i++) v[i] = rand()%lim;

	printvet(v, T);

	mergesort(v, 0, 99);

	printvet(v, T);

	return 0;
}
