#include<stdio.h>
#include<stdlib.h>

int *char_counter(char *v, int tam){
    int *aux = (int*) malloc(tam*sizeof(int));
    for(int i=0; i<tam; i++) aux[i] = 0;
    for(int i=0; i<tam; i++){
        if(v[i] == 'a') aux[0]++;
        if(v[i] == 'e') aux[1]++;
        if(v[i] == 'i') aux[2]++;
    }
    return aux;
}

void check_comb(char *v, int tam, int pos, int n, char *aux){
    if(pos == n){
        int* c = char_counter(v, tam);
        if(c[0] > c[1]+c[2]){
            for(int i=0; i<n; i++) printf("%c", v[i]);
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

    char aux[] = {'a', 'e', 'i'};
    int tam = 3;
    int n=5;
    char *v = (char*) malloc(n*sizeof(char));

    check_comb(v, tam, 0, n, aux);

}