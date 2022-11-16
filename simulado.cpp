#include<bits/stdc++.h>

using namespace std;

#define N 10

void printvector(int *vector, int tam){
    for(int i=0; i<tam; i++) cout << vector[i] << " ";
    cout << endl;
}

void quicksortchange(int *x, int *y){
    int aux = *y;
    *y = *x;
    *x = aux;
}

void quicksort(int begin, int end, int *vector){
    if(end > begin){
        int x = begin;
        int l = begin;

        for(int i=l; i<=end; i++){
            if(vector[i]<=vector[x]){
                quicksortchange((vector+i),(vector+l));
                l++;
            }
        }
        l--;
        quicksortchange((vector+l),(vector+x));
        x = l;
        quicksort(begin, x-1, vector);
        quicksort(x+1, end, vector);
    }
}

void trocavet(int **x, int **y){
    int *aux;
    aux=*x;
    *x=*y;
    *y=aux;
}

int main(){
    // quicksort is a divide conquer strategy method of sorting something.
    // it takes an element of the list and moves all elements which are smaller than it to its left
    // then it takes all the elements of the list which are bigger to the right side of it
    // if we have made all the comparisons and moved the elements to its place then we can conclude
    // that it doesn't matter how many elements are left, we have reached the right position to
    // the first element we have chosen, also called pivot. With all that said, simply repeat the
    // process again to the two arrays we have got left, making the divide conquer strategy happen.
    int *vector;
    int *vet;

    vector = (int *) malloc(N*sizeof(int));
    vet = (int *) malloc(N*sizeof(int));

    for(int i=0; i<N; i++){
        vector[i]=i%3;
    }
    for(int i=0; i<N; i++){
        vet[i]=i;
    }
    

    printvector(vector, N);
    printvector(vet, N);
    trocavet(&vector, &vet);
    printvector(vector, N);
    printvector(vet, N);
    


}