#include<stdio.h>
#include<stdlib.h>

int *int_counter(int *v, int tam){
    int *aux = (int*) malloc(tam*sizeof(int));
    for(int i=0; i<tam; i++) aux[i] = 0;
    for(int i=0; i<tam; i++){
        if(v[i] == 15) aux[0]++;
        if(v[i] == 31) aux[1]++;
        if(v[i] == 55) aux[2]++;
        if(v[i] == 44) aux[3]++;
    }
    return aux;
}

void check_comb(int *v, int tam, int pos, int n, int *aux){
    if(pos == n){
        int* c = int_counter(v, tam);
        if((c[0]*aux[0]+c[1]*aux[1]+c[2]*aux[2]+c[3]*aux[3])%2 == 0){
            for(int i=0; i<n; i++) printf("%d ", v[i]);
            printf("\n");
        }
    }
    else{
        for(int i=0; i<tam; i++){
            v[pos] = aux[i];
            check_comb(v, tam, pos+1, n, aux);
        }
    }
}

int main(){

    int aux[] = {15, 31, 55, 44};
    int tam = 4;
    int n=2;
    int *v = (int*) malloc(n*sizeof(int));

    check_comb(v, tam, 0, n, aux);

}