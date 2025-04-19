#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

struct Fila{
    int ini;
    int fim;
    int v[100];
};

fila filaInicializar(){
    fila p = (fila) malloc(sizeof(struct Fila));
    p->ini = 0;
    p->fim = 0;
    return p;
}

void filaInserir(fila p, int info){
    p->v[p->fim] = info;
    p->fim = (p->fim+1)%100;
}

int filaRemover(fila p){
    if (!filaIsVazia(p)){
        int info = p->v[p->ini];
        p->ini = (p->ini+1)%100;
        return info;
    }
    else{
        return -1;
    }
}

int filaIsVazia(fila p){
    return (p->ini == p->fim);
}

void filaImprimir(fila p){
    printf("[ ");
    int i = p->ini;
    while(i!=p->fim){
        printf("%d ", p->v[i]);
        i = (i+1)%100;
    }
    printf("]\n");
}

void filaDestruir(fila p){
    free(p);
}